# pybricks
ネット上に公開されているpybricks向けのプログラムをSpuke-rt用に書き直したものです。

## 概要
### sbc (Small Ball Contraption)
- 下記サイトで公開されているプログラム(Python)をspike-rtで実現したもの
    - https://legostudiovives.be/spikeprimesmallballcontraption/
    - 組み立て方法やオリジナルのプログラムが公開されています。

## 使用方法
- 移動してビルド
    ```
    cd spike-rt-sample/pybricks/sbc
    make
    ```
- HubをDFUモードにする
    - DFUモード参考：https://www.youtube.com/watch?v=XJ7rltuf3Jc
- Hubにプログラムを書き込む
    ```
    make deploy-win     # WSL2の場合
    make deploy-lin     # Ubuntu(ネイティブ)の場合
    ```