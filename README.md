# 数値計算 テンプレート
## About
- 数値計算の課題のテンプレートです。
- 行列やベクトルの入出力を実装済みです。
- 先生の許可は取ってません。
- 教科書ベースですが、オリジナルで書き直しています。
    - そもそも教科書のプログラムがめちゃめちゃなので作りました。
- 改変・二次配布自由。

## ダウンロード
- 画面右の方の`Clone or download`の`Download ZIP`でDLして展開すればいいと思われます

## 内容物
- *kadai\_template.c*
    - プログラム本体。
    - main関数を書き換えたり、自作関数を追加したりして課題を解決してください。
- *README.md*
    - この説明が書いてあるファイル。
    - 中身はテキストファイルなのでメモ帳等で開けます。
- *LICENSE*
    - ライセンスが書いてあるファイル。
    - これも中身はテキストファイルなのでメモ帳等で開けます。
- *.gitigrone*
    - 隠しファイルなので人によっては見えないです。
    - github(このサイト)の管理用のファイルなので触らないでください。

## 注意点
- Visual Studioでは`fopen`や`scanf`がエラーします。
    - 各自解決方法は調べてください

## お家でC言語を書く方法
- <a href="https://paiza.io/ja" target="_blank">paiza.io</a>が有能です。
    1. 「コード作成を試してみる」
    1. 左上の緑のボタンをクリックして「C」を選択
    1. 黒い所にソースコードをコピペ
    1. 下の方の「入力」と書いてあるところより下にscanfで入力する数字を予め入れておく。
    1. 「実行」を押す
    1. 結果が下の方に出てくる

## 各関数の使い方
### double **dmatrix(int nr1, int nr2, int nl1, int nl2);
- 行列の領域を動的に確保します。
- 行の添字がnr1〜nr2まで、列の添字がnl1〜nl2までの行列の領域を確保します。
- 例えば、行の添字が1〜3、列の添字が1〜2の3×2行列を作る場合は、次のように記述します。

```
    double **a; // 行列の領域を確保する場合は*が2つ
    a = dmatrix(1, 3, 1, 2);
```

### void key\_input\_dmatrix(double **a, int nr1, int nr2, int nl1, int nl2);
- 行列をキーボードから入力します。
- 行の添字がnr1〜nr2まで、列の添字がnl1〜nl2までの行列の入力をします。
- 例えば、行の添字が1〜3、列の添字が1〜2の3×2行列`a`を入力する場合は、次のように記述します。

```
    double **a; // 行列の領域を確保する場合は*が2つ
    a = dmatrix(1, 3, 1, 2);
    key_input_dmatrix(a, 1, 3, 1, 2);
```

### void print_dmatrix(double **a, int nr1, int nr2, int nl1, int nl2);
- 行列を画面に出力します。
- 行の添字がnr1〜nr2まで、列の添字がnl1〜nl2までの行列の出力をします。
- 例えば、行の添字が1〜3、列の添字が1〜2の3×2行列`a`を出力する場合は、次のように記述します。

```
    print_dmatrix(a, 1, 3, 1, 2);
```

### void free_dmatrix(double **a, int nr1, int nr2, int nl1, int nl2);
- 動的に確保した行列の領域を開放します。
- 確保したら必ず最後に開放してください。
- 行の添字がnr1〜nr2まで、列の添字がnl1〜nl2までの行列の解放をします。
- 例えば、行の添字が1〜3、列の添字が1〜2の3×2行列`a`を解放する場合は、次のように記述します。

```
    free_dmatrix(a, 1, 3, 1, 2);
```

### double *dvector(int i, int j);
- ベクトルの領域を動的に確保します。
- 添字がi〜jのベクトルを確保します。
- 例えば、添字が2〜5の4次ベクトルを作る場合は、次のように記述します。

```
    double *b; // ベクトルの領域を確保する場合は*が1つ
    b = dvector(2, 5);
```

### void key\_input\_dvector(double *b, int i, int j);
- ベクトルをキーボードから入力します。
- 添字がi〜jのベクトルを入力します。
- 例えば、添字が2〜5の4次ベクトル`b`を作る場合は、次のように記述します。

```
    double *b; // ベクトルの領域を確保する場合は*が1つ
    b = dvector(2, 5);
    key_input_dvector(b, 2, 5);
```

### void print_dvector(double *b, int i, int j);
- ベクトルを画面に出力します。
- 添字がi〜jのベクトルを出力します。
- 例えば、添字が2〜5の4次ベクトル`b`を出力する場合は、次のように記述します。

```
    print_dvector(b, 2, 5);
```

### void free_dvector(double *b, int i, int j);
- 動的に確保したベクトルの領域を開放します。
- 確保したら必ず最後に開放してください。
- 添字がi〜jのベクトルの解放をします。
- 例えば、添字が2〜5の4次ベクトル`b`を解放する場合は、次のように記述します。

```
    free_dvector(a, 2, 5);
```


## 製作者
- lalaso2000
- 問題があれば<a href="https://github.com/lalaso2000/NITGifu-E-SuchikeisanTemplate/issues" target="_blank">#issue</a>までお知らせください。

## ライセンス
- <a href="https://choosealicense.com/licenses/unlicense/" target="_blank">Unlicense</a>
    - 個人利用、商用利用、修正、配布、サブライセンスが認められます。
