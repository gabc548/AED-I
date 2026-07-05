#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ArvoreNode{
    int val;
    int tamanho;
    int altura;
    int qttDireita;
    struct ArvoreNode *left;
    struct ArvoreNode *right;
};

typedef struct ArvoreNode ArvoreNode;

ArvoreNode *Inserir( ArvoreNode *raiz, int valor, long long int *paresGlobais );

static int Altura( const ArvoreNode *n );

static int Tamanho( const ArvoreNode *n );

static void Atualizar( ArvoreNode *n );

static ArvoreNode *Rotacaodireita( ArvoreNode *y );

static ArvoreNode *Rotacaoesquerda( ArvoreNode *x );

static int FatorBalanceamento( const ArvoreNode *n );

static ArvoreNode *Rebalancear( ArvoreNode *n );

void Liberar( ArvoreNode *n );


bool isIdealPermutation( int *nums, int numsSize );



int main(){

    int		t1[]  = { 1, 0, 2 };				// true
	int		t2[]  = { 1, 2, 0 };				// false
	int		t3[]  = { 0 };						// true
	int		t4[]  = { 0, 1, 2, 3, 4 };			// true
	int		t5[]  = { 1, 0, 3, 2, 4 };			// true
	int		t6[]  = { 2, 0, 1 };				// false
	int		t7[]  = { 4, 3, 2, 1, 0 };			// false
	int		t8[]  = { 0, 2, 1 };				// true
	int		t9[]  = { 1, 0, 2, 4, 3 };			// true
	int		t10[] = { 3, 0, 1, 2 };				// false

    printf("%d\n", isIdealPermutation(t1, 3));
    printf("%d\n", isIdealPermutation(t2, 3));
    printf("%d\n", isIdealPermutation(t3, 1));
    printf("%d\n", isIdealPermutation(t4, 5));
    printf("%d\n", isIdealPermutation(t5, 5));
    printf("%d\n", isIdealPermutation(t6, 3));
    printf("%d\n", isIdealPermutation(t7, 5));
    printf("%d\n", isIdealPermutation(t8, 4));
    printf("%d\n", isIdealPermutation(t9, 5));
    printf("%d\n", isIdealPermutation(t10, 4));
}

bool isIdealPermutation( int *nums, int numsSize ) {
    ArvoreNode *root;
    root = NULL;
    long long int paresLocais = 0, paresGlobais = 0;

    for( int i = 0; i < numsSize; i++ ) {
        root = Inserir( root, nums[i], &paresGlobais );
    }

    for( int i = 0; i < numsSize - 1; i++ ) {
        if( nums[i] > nums[i + 1] ) {
            paresLocais++;
        }
    }

    Liberar( root );

    return paresGlobais == paresLocais;
}


static ArvoreNode *Rebalancear( ArvoreNode *n ) {
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

static int FatorBalanceamento( const ArvoreNode *n ) {

	return Altura( n->left ) - Altura( n->right );
}

static ArvoreNode *Rotacaoesquerda( ArvoreNode *x ) {
	ArvoreNode *	y;

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

static ArvoreNode *Rotacaodireita( ArvoreNode *y ) {
	ArvoreNode *	x;

	x = y->left;
	y->left = x->right;
	x->right = y;
    x->qttDireita = y->qttDireita + 1;
	Atualizar( y );
	Atualizar( x );
	return x;
}

static void Atualizar( ArvoreNode *n ) {
	int		he;
	int		hd;

	he = Altura( n->left );
	hd = Altura( n->right );
	n->altura = ( he > hd ? he : hd ) + 1;
	n->tamanho = 1 + Tamanho( n->left ) + Tamanho( n->right );
}

static int Tamanho( const ArvoreNode *n ) {
	return n ? n->tamanho : 0;
}

static int Altura( const ArvoreNode *n ) {
	return n ? n->altura : 0;
}

ArvoreNode *Inserir( ArvoreNode *raiz, int valor, long long int *paresGlobais ) {
	ArvoreNode *	n;

	if ( !raiz ) {
		n = (ArvoreNode*)malloc( sizeof( ArvoreNode ) );
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

void Liberar( ArvoreNode *n ) {
	if ( !n ) {
		return;
	}
	Liberar( n->left );
	Liberar( n->right );
	free( n );
}