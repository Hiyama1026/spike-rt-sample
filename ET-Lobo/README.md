# ET_Lobo
ETロボコンの走行体(LEGO SPIKE)をSpike-rtの環境で動かすサンプルです。

## 各サンプルの機能概要
### basic_LT
- 走行体をP制御でライントレースさせる。
- RasPike環境用に用意されたサンプル([sample_c5](https://github.com/ETrobocon/RasPike/tree/master/sdk/workspace/sample_c5))を参考にして作成した。
### pid_controller_LT
- 走行体をPID制御でライントレースさせる。
### switch_edge_LT
- 走行中に走行エッジを切り替える。
- エンコーダー値を取得し, 左車輪が3回転したら走行エッジを左から右に切り替える。
- ハブに輝度のターゲット値を表示する。

## ETロボコン用環境(RasPike)について
- 詳しくは[こちら](https://github.com/ETrobocon/RasPike)。
- 走行体は、[組立図](https://drive.google.com/file/d/17FyQBsuuXrV4BK-96fgQJy-Ou4NvqLi7/view?usp=sharing)を元に組み立てました。