# Spike-rt sample
## 注意事項
- このサンプルは[spike-rt](https://github.com/spike-rt/spike-rt)内のbuildディレクトリの直下に展開すると実行することが出来ます。bildディレクトリが無い場合はsampleディレクトリに展開しても実行できます。
- 1回目のビルド時にエラーが出るかもしれません。その場合はもう一度ビルドをしてみてください。2回目のビルドで問題なく実行できるようになります。

## API 
- Spike API
    - [APIドキュメント](https://spike-rt.github.io/spike-rt/ja/html/modules.html)を参照。
- SpikeとPybriksAPIの対応
    - [PybricksAndSpike_API.md](/PybricksAndSpike_API.md) を参照。

## その他
### pybricksディレクトリ内のサンプルについて
ネット上に公開されているpybricks向けのプログラムをC言語で書き直したものです。概要は次の通りです。
#### sbc (Small Ball Contraption)
- [参考元URL](https://legostudiovives.be/spikeprimesmallballcontraption/)
    - 組み立て方法やオリジナルのプログラムが公開されています。

### API-sampleディレクトリ内のサンプルについて
APIの使い方の確認等に使用することを想定したサンプルです。どのサンプルでどのAPIを使用しているかは、[API-sample/index.md](/API-sample/index.md)を参照してください。

### ETロボコン用環境(RasPike)について
- 詳しくは[こちら](https://github.com/ETrobocon/RasPike)。
- 走行体は、[組立図](https://drive.google.com/file/d/17FyQBsuuXrV4BK-96fgQJy-Ou4NvqLi7/view?usp=sharing)を元に組み立てました。
