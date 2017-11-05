// 数値計算 テンプレート
// autor : lalaso2000
// 行列やベクトルの入力、出力が実装済みです
// 詳しい使い方はREADME.mdを参照
// サンプルとして、1回目の課題が書いてあります

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 定数=================================================================
#define N 3     // N次行列
// 定数ここまで=========================================================


// 行列の領域確保
double **dmatrix(int nr1, int nr2, int nl1, int nl2);
// キーボードから行列を取得
void key_input_dmatrix(double **a, int nr1, int nr2, int nl1, int nl2);
// 行列を出力
void print_dmatrix(double **a, int nr1, int nr2, int nl1, int nl2);
// 行列の領域解放
void free_dmatrix(double **a, int nr1, int nr2, int nl1, int nl2);

// ベクトルの領域確保
double *dvector(int i, int j);
// キーボードからベクトルを取得
void key_input_dvector(double *b, int i, int j);
// ベクトルを出力
void print_dvector(double *b, int i, int j);
// ベクトルの領域解放
void free_dvector(double *b, int i, int j);


//=====================================================================
//  main関数
//=====================================================================
int main(void){
    double **a;     // 行列を使う場合はアスタリスクを二つ
    double *b;      // ベクトルを使う場合はアスタリスクを一つ

    int i, j;       // ループ用変数
    double tmp;     // 計算用変数
    double *ans;    // A・bの答えを代入


    /* ======行列の使い方====== */
    // 各関数では、行の添字がnr1~nr2であること、列の添字がnl1~nl2であることを指定する必要があります。
    // 1.行列の領域を確保(行の添字が1~N、列の添字が1~N)
    a = dmatrix(1, N, 1, N);
    // 2.行列を入力
    key_input_dmatrix(a, 1, N, 1, N);
    // 3.行列を出力
    printf("\n======行列A======\n");
    print_dmatrix(a, 1, N, 1, N);
    printf("\n");


    /* ======ベクトルの使い方====== */
    // 各関数では、添字がi~jであることを指定する必要があります。
    // 1.ベクトルの領域を確保(添字が1~N)
    b = dvector(1, N);
    // 2.ベクトルを入力
    key_input_dvector(b, 1, N);
    // 3.ベクトルを出力
    printf("\n======ベクトルb======\n");
    print_dvector(b, 1, N);
    printf("\n");



    /* ======以下、サンプルとして1回目の課題の解法====== */
    // この辺をいじって課題を解決してください

    // ansのベクトル領域を確保
    ans = dvector(1, N);
    // A・bのを実行
    for (i = 1; i <= N; i++){
        tmp = 0.0;
        for (j = 1; j <= N; j++){
            tmp += a[i][j] * b[j];
        }
        ans[i] = tmp;
    }

    // A・bの結果を出力
    printf("======A・bの結果======\n");
    print_dvector(ans, 1, N);



    /* ======行列・ベクトルを使ったら必ずメモリ解放をしてください！====== */
    // 行列・ベクトルの領域を解放
    free_dmatrix(a, 1, N, 1, N);
    free_dvector(b, 1, N);
    free_dvector(ans, 1, N);

    return 0;
}
//=====================================================================
//  main関数 ここまで
//=====================================================================




//=====================================================================
//  この先は各種関数の定義
//=====================================================================
// キーボードから行列を取得
// [nr1][nl1] ~ [nr2][nl2]までの要素を入力
void key_input_dmatrix(double **a, int nr1, int nr2, int nl1, int nl2){
    int i, j;

    printf("%d×%d次の行列を入力します。\n", nr2 - nr1 + 1, nl2 - nl1 + 1);
    for (i = nr1; i <= nr2; i++){
        for (j = nl1; j <= nl2; j++){
            printf("[%d][%d]成分を入力 > ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
}


// キーボードからベクトルを取得
// [i] ~ [j]までの要素を入力
void key_input_dvector(double *b, int i, int j){
    int k;

    printf("%d次のベクトルを入力します。\n", j - i + 1);
    for (k = i; k <= j; k++){
        printf("[%d]成分を入力 > ", k);
        scanf("%lf", &b[k]);
    }
}


// 行列を出力
// [nr1][nl1] ~ [nr2][nl2]までの要素を出力
void print_dmatrix(double **a, int nr1, int nr2, int nl1, int nl2){
    int i, j;
    for (i = nr1; i <= nr2; i++){
        for (j = nl1; j <= nl2; j++){
            printf("%.3f\t", a[i][j]);
        }
        printf("\n");
    }
}


// ベクトルを出力
// [i] ~ [j]までの要素を入力
void print_dvector(double *b, int i, int j){
    int k;
    for (k = i; k <= j; k++){
        printf("%.3f\n", b[k]);
    }
}


// 行列の領域確保
// [nr1][nl1] ~ [nr2][nl2]までを確保
double **dmatrix(int nr1, int nr2, int nl1, int nl2){
    int i, nrow, ncol;
    double **a;

    nrow = nr2 - nr1 + 1;   // 行の数
    ncol = nl2 - nl1 + 1;   // 列の数

    // 行の確保
    if ((a = malloc(nrow * sizeof(double *))) == NULL){
        printf("メモリ領域が確保できません。(dmatrix)\n");
        exit(1);
    }
    a = a - nr1;    // 行をずらす

    // 列の確保
    for (i = nr1; i <= nr2; i++){
        a[i] = malloc(ncol * sizeof(double));
    }
    for (i = nr1; i <= nr2; i++){
        a[i] = a[i] - nl1;  // 列をずらす
    }

    return a;
}


// 行列の領域解放
// [nr1][nl1] ~ [nr2][nl2]までを解放
void free_dmatrix(double **a, int nr1, int nr2, int nl1, int nl2){
    int i;

    // メモリの解放
    for (i = nr1; i <= nr2; i++){
        free((void *)(a[i] + nl1));
    }
    free((void *)(a + nr1));
}


// ベクトルの領域確保
// [i] ~ [j]までを確保
double *dvector(int i, int j){
    double *b;

    if((b = malloc( (j - i + 1) * sizeof(double) )) == NULL){
        printf("メモリ領域が確保できません。(dvector)\n");
        exit(1);
    }

    return b - i;
}


// ベクトルの領域解放
// [i] ~ [j]までを解放
void free_dvector(double *b, int i, int j){
    // jは必要ないけど他の関数と統一性が無いため
    free((void *)(b + i));
}