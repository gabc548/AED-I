#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct TreeNode{
    int val;
    int tamanho;
    int altura;
    int qttDireita;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *Inserir( TreeNode *raiz, int valor, int *paresGlobais );

static int Altura( const TreeNode *n );

static int Tamanho( const TreeNode *n );

static void Atualizar( TreeNode *n );

static TreeNode *Rotacaodireita( TreeNode *y );

static TreeNode *Rotacaoesquerda( TreeNode *x );

static int FatorBalanceamento( const TreeNode *n );

static TreeNode *Rebalancear( TreeNode *n );


bool isIdealPermutation(int *nums, int numsSize){
    TreeNode *root;
    root = NULL;
    int paresLocais = 0, paresGlobais = 0;

    for(int i = 0; i < numsSize; i++){
        root = Inserir(root, nums[i], &paresGlobais);
    }

    printf("%d\n", paresGlobais);

    for(int i = 0; i < numsSize - 1; i++){
        if(nums[i] > nums[i + 1]){
            paresLocais++;
        }
    }

    printf("%d\n", paresLocais);

    return paresGlobais == paresLocais;
}

void Liberar_r( TreeNode *n ) {
	if ( !n ) {
		return;
	}
	Liberar_r( n->left );
	Liberar_r( n->right );
	free( n );
}

/*
====================
isIdealPermutation

	RESOLVER ESSA FUNCAO USANDO ARVORE AVL PARA CONTAR O NUMERO DE INVERSOES GLOBAIS.
	
====================
*/

/*
====================
ForcaBruta

	Referencia O( n^2 ) usada para conferir os resultados dos testes.
====================
*/

static bool ForcaBruta( const int *nums, int n ) {
	long long	global;
	long long	local;
	int			i;
	int			j;

	global = 0;
	for ( i = 0; i < n; i++ ) {
		for ( j = i + 1; j < n; j++ ) {
			if ( nums[i] > nums[j] ) {
				global++;
			}
		}
	}

	local = 0;
	for ( i = 0; i + 1 < n; i++ ) {
		if ( nums[i] > nums[i + 1] ) {
			local++;
		}
	}

	return global == local;
}

/*
====================
ImprimirArray
====================
*/
static void ImprimirArray( const int *a, int n ) {
	int		i;

	printf( "[" );
	for ( i = 0; i < n; i++ ) {
		printf( "%d%s", a[i], i + 1 < n ? "," : "" );
	}
	printf( "]" );
}

/*
====================
RodarTeste
====================
*/
static int RodarTeste( int num, int *nums, int n, bool esperado ) {
	bool	obtido;
	bool	bruto;
	int		ok;

	obtido = isIdealPermutation( nums, n );
	bruto = ForcaBruta( nums, n );
	ok = ( obtido == esperado ) && ( bruto == esperado );

	printf( "Teste %2d: nums = ", num );
	ImprimirArray( nums, n );
	printf( "\n  esperado = %s | avl = %s | forca bruta = %s  ->  %s\n\n",
			esperado ? "true" : "false",
			obtido ? "true" : "false",
			bruto ? "true" : "false",
			ok ? "OK" : "FALHOU" );
	return ok;
}

/*
====================
main
====================
*/
int main() {
	int		passou;

	int		t1[]  = { 1, 0, 2 };				/* exemplo 1 do enunciado             */
	int		t2[]  = { 1, 2, 0 };				/* exemplo 2 do enunciado             */
	int		t3[]  = { 0 };						/* elemento unico                     */
	int		t4[]  = { 0, 1, 2, 3, 4 };			/* identidade: zero inversoes         */
	int		t5[]  = { 1, 0, 3, 2, 4 };			/* trocas adjacentes disjuntas        */
	int		t6[]  = { 2, 0, 1 };				/* valor a 2 posicoes do lugar        */
	int		t7[]  = { 4, 3, 2, 1, 0 };			/* permutacao reversa                 */
	int		t8[]  = { 0, 2, 1 };				/* uma troca adjacente no fim         */
	int		t9[]  = { 1, 0, 2, 4, 3 };			/* trocas nas duas pontas             */
	int		t10[] = { 3, 0, 1, 2 };				/* 3 globais, 1 local                 */

	passou = 0;
	passou += RodarTeste(  1, t1,  3, true );
	passou += RodarTeste(  2, t2,  3, false );
	passou += RodarTeste(  3, t3,  1, true );
	passou += RodarTeste(  4, t4,  5, true );
	passou += RodarTeste(  5, t5,  5, true );
	passou += RodarTeste(  6, t6,  3, false );
	passou += RodarTeste(  7, t7,  5, false );
	passou += RodarTeste(  8, t8,  3, true );
	passou += RodarTeste(  9, t9,  5, true );
	passou += RodarTeste( 10, t10, 4, false );                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         

	printf( "Resultado final: %d/10 testes passaram\n", passou );
	return passou == 10 ? 0 : 1;
}

static TreeNode *Rebalancear( TreeNode *n ) {
	int		fb;

	Atualizar( n );
	fb = FatorBalanceamento( n );

	if ( fb > 1 ) {
		if ( FatorBalanceamento( n->left ) < 0 ) {
			n->left = Rotacaoesquerda( n->left );
		}
		return Rotacaodireita( n );
	}
	if ( fb < -1 ) {
		if ( FatorBalanceamento( n->right ) > 0 ) {
			n->right = Rotacaodireita( n->right );
		}
		return Rotacaoesquerda( n );
	}
	return n;
}

static int FatorBalanceamento( const TreeNode *n ) {

	return Altura( n->left ) - Altura( n->right );
}

static TreeNode *Rotacaoesquerda( TreeNode *x ) {
	TreeNode *	y;

	y = x->right;
	x->right = y->left;
	y->left = x;
    if(x->right == NULL){
        x->qttDireita = 0;
    } else{
        x->qttDireita = x->right->qttDireita + 1;
    }
	Atualizar( x );
	Atualizar( y );
	return y;
}

static TreeNode *Rotacaodireita( TreeNode *y ) {
	TreeNode *	x;

	x = y->left;
	y->left = x->right;
	x->right = y;
    x->qttDireita = y->qttDireita + 1;
	Atualizar( y );
	Atualizar( x );
	return x;
}

static void Atualizar( TreeNode *n ) {
	int		he;
	int		hd;

	he = Altura( n->left );
	hd = Altura( n->right );
	n->altura = ( he > hd ? he : hd ) + 1;
	n->tamanho = 1 + Tamanho( n->left ) + Tamanho( n->right );
}

static int Tamanho( const TreeNode *n ) {
	return n ? n->tamanho : 0;
}

static int Altura( const TreeNode *n ) {
	return n ? n->altura : 0;
}

TreeNode *Inserir( TreeNode *raiz, int valor, int *paresGlobais ) {
	TreeNode *	n;

	if ( !raiz ) {
		n = (TreeNode*)malloc( sizeof( TreeNode ) );
		n->val = valor;
		n->tamanho = 1;
		n->altura = 1;
        n->qttDireita = 0;
		n->left = NULL;
		n->right = NULL;
		return n;
	}
	if ( valor < raiz->val ) {
        (*paresGlobais) = (*paresGlobais) + raiz->qttDireita + 1;
		raiz->left = Inserir( raiz->left, valor, paresGlobais );
	} else {
        (raiz->qttDireita)++;
		raiz->right = Inserir( raiz->right, valor, paresGlobais );
	}
	return Rebalancear( raiz );
}