# JYD物联网专项赛 --- 嵌入式端与前端交互命令表

## 数据格式

> * 统一使用JSON格式发送消息、返回结果
>
> * 发送消息：
>
>   ```json
>   {
>       "cmd": 1,
>       "strArg": "str1",
>       "intArg": 123
>   }
>   ```
>
> * 返回结果：
>
>   ```json
>   {
>       "res": 0,
>       "cmd": 1
>   }
>   ```
>
>   * res：成功返回0,非0表示失败

## WiFi前端部分JSON指令

### 获取传感器的3轴速度平均值数据

> 寄存器: 0~2 
>
> start: 0;   length: 2*3
>
> 指令:
>
> ``` json
> {
> 	"cmd":1
> }
> ```
>
> 返回值:
>
> ``` json
> {
>  	"res":0,
>  	"cmd":1,
> 	"x_speed":100,
>  	"y_speed":20,
>  	"z_speed":5
> }
> ```



### 获取传感器的温度值

> 寄存器: 3 
>
> start: 3;   length: 2*1
>
> 指令:
>
> ``` json
> {
> 	"cmd":2
> }
> ```
>
> 返回值:
>
> ``` json
> {
>  	"res":0,
>  	"cmd":2,
> 	"temp":26
> }
> ```



### 获取传感器的3轴加速度数据

> 寄存器: 4~6 
>
> start: 4;   length: 2*3
>
> 指令:
>
> ``` json
> {
> 	"cmd":3
> }
> ```
>
> 返回值:
>
> ``` json
> {
>  	"res":0,
>  	"cmd":3,
> 	"x_acc":6,
>  	"y_acc":12,
>  	"z_acc":4
> }
> ```



### 获取传感器的3轴速度最大值, 速度峭度平均值, 加速度最大值, 加速度峭度平均值

> 寄存器: 7~18
>
> start: 7;	length: 2*12
>
> 指令:
>
> ``` json
> {
> 	"cmd":4
> }
> ```
>
> 返回值:
>
> ``` json
> {
>  	"res":0,
>  	"cmd":4,
> 	"x_speedmax":100,
>     "x_speedkrt": 10,
>     "x_accmax":8,
>     "x_acckrt":9,
>     "y_speedmax":80,
>     "y_speedkrt": 20,
>     "y_accmax":9,
>     "y_acckrt":13,
>     "z_speedmax":50,
>     "z_speedkrt": 3,
>     "z_accmax":13,
>     "z_acckrt":2,
> }
> ```
>
> speedmax: 速度最大值
>
> speedkrt:速度峭度平均值
>
> accmax:加速度最大值
>
> acckrt:加速度峭度平均值



### 获取传感器的3轴位移峰峰值

> 寄存器: 19~21
>
> start: 19;	length: 2*3
>
> 指令:
>
> ``` json
> {
> 	"cmd":5
> }
> ```
>
> 返回值:
>
> ``` json
> {
>  	"res":0,
>  	"cmd":5,
> 	"x_dispeek":20,
>  	"y_dispeek":12,
>  	"z_dispeek":9
> }
> ```



### 获取传感器的X轴加速度频谱分析数据

> **获取传感器的X轴关注点1~8, 关注带1~8加速度谱能量, 加速度谱最高能量点阶次, 加速度谱总能量**
>
> **获取传感器的X轴加速度谱特征值**
>
> 寄存器: 22~43
>
> start: 22;	length: 2*22
>
> 指令:
>
> ``` json
> {
> 	"cmd":6
> }
> ```
>
> 返回值:
>
> ``` json
> {
>  	"res":0,
>  	"cmd":6,
> 	"fft_count":26,
>  	"channalID":1,
>  	"rotate_speed":20,
>     "inside_eigenvalue":26,
>  	"outside_eigenvalue":29,
>  	"roll_eigenvalue":20,
>     "shell_eigenvalue":13,
>     "point_1":10,
>     "point_2":10,
>     "point_3":10,
>     "point_4":10,
>     "point_5":10,
>     "point_6":10,
>     "point_7":10,
>     "point_8":10,
>     "band_1":13,
>     "band_2":13,
>     "band_3":13,
>     "band_4":13,
>     "band_5":13,
>     "band_6":13,
>     "band_7":13,
>     "band_8":13,
>     "maxpower_order":2,
>     "total_power":999
> }
> ```
>
> fft_count: 频谱分析周期计数
>
> channalID:振动通道ID
>
> rotate_speed:当前转速
>
> inside_eigenvalue: 内圈特征值1X -- 加速度谱
>
> outside_eigenvalue:外圈特征值
>
> roll_eigenvalue:滚动体特征值
>
> shell_eigenvalue: 保持架特征值
>
> point1~8: 关注点1~8加速度谱能量
>
> band1~8: 关注带1~8加速度谱能量
>
> maxpower_order: 最高能量点阶次
>
> total_power: 总能量



### 获取传感器的X轴速度频谱分析数据

> **获取传感器的X轴关注点1~8, 关注带1~8速度谱能量, 速度谱最高能量点阶次, 速度谱总能量**
>
> **获取传感器的X轴速度谱特征值**
>
> 寄存器: 44~62
>
> start: 44;	length: 2*19
>
> 指令:
>
> ``` json
> {
> 	"cmd":7
> }
> ```
>
> 返回值:
>
> ``` json
> {
>  	"res":0,
>  	"cmd":7,
> 	"paddle_eigenvalue_1": 1,
>     "paddle_eigenvalue_2": 2,
>     "paddle_eigenvalue_3": 3,
>     "paddle_eigenvalue_4": 4,
>     "point_1":10,
>     "point_2":10,
>     "point_3":10,
>     "point_4":10,
>     "point_5":10,
>     "point_6":10,
>     "point_7":10,
>     "point_8":10,
>     "band_1":13,
>     "band_2":13,
>     "band_3":13,
>     "band_4":13,
>     "band_5":13,
>     "band_6":13,
>     "band_7":13,
>     "band_8":13,
>     "maxpower_order":2,
>     "total_power":999
> }
> ```
>
> paddle_eigenvalue_1~4: 叶片特征值1~4
>
> point1~8: 关注点1~8速度谱能量
>
> band1~8: 关注带1~8速度谱能量
>
> maxpower_order: 速度谱最高能量点阶次
>
> total_power: 速度谱总能量



### 获取传感器的Y轴加速度频谱分析数据

> **获取传感器的Y轴关注点1~8, 关注带1~8加速度谱能量, 加速度谱最高能量点阶次, 加速度谱总能量**
>
> **获取传感器的Y轴加速度谱特征值**
>
> 寄存器: 63~83
>
> start: 63;	length: 2*21
>
> 指令:
>
> ``` json
> {
> 	"cmd":8
> }
> ```
>
> 返回值:
>
> ``` json
> {
>  	"res":0,
>  	"cmd":8,
> 	"fft_count":26,
>  	"channalID":2,
>  	"rotate_speed":20,
>     "inside_eigenvalue":26,
>  	"outside_eigenvalue":29,
>  	"roll_eigenvalue":20,
>     "shell_eigenvalue":13,
>     "point_1":10,
>     "point_2":10,
>     "point_3":10,
>     "point_4":10,
>     "point_5":10,
>     "point_6":10,
>     "point_7":10,
>     "point_8":10,
>     "band_1":13,
>     "band_2":13,
>     "band_3":13,
>     "band_4":13,
>     "band_5":13,
>     "band_6":13,
>     "band_7":13,
>     "band_8":13,
>     "maxpower_order":2,
>     "total_power":999
> }
> ```
>
> fft_count: 频谱分析周期计数
>
> channalID:振动通道ID
>
> rotate_speed:当前转速
>
> inside_eigenvalue: 内圈特征值1X -- 加速度谱
>
> outside_eigenvalue:外圈特征值
>
> roll_eigenvalue:滚动体特征值
>
> shell_eigenvalue: 保持架特征值
>
> point1~8: 关注点1~8加速度谱能量
>
> band1~8: 关注带1~8加速度谱能量
>
> maxpower_order: 最高能量点阶次
>
> total_power: 总能量



### 获取传感器的Y轴速度频谱分析数据

> **获取传感器的Y轴关注点1~8, 关注带1~8速度谱能量, 速度谱最高能量点阶次, 速度谱总能量**
>
> **获取传感器的Y轴速度谱特征值**
>
> 寄存器: 84~102
>
> start: 84;	length: 2*19
>
> 指令:
>
> ``` json
> {
> 	"cmd":9
> }
> ```
>
> 返回值:
>
> ``` json
> {
>  	"res":0,
>  	"cmd":9,
> 	"paddle_eigenvalue_1": 1,
>     "paddle_eigenvalue_2": 2,
>     "paddle_eigenvalue_3": 3,
>     "paddle_eigenvalue_4": 4,
>     "point_1":10,
>     "point_2":10,
>     "point_3":10,
>     "point_4":10,
>     "point_5":10,
>     "point_6":10,
>     "point_7":10,
>     "point_8":10,
>     "band_1":13,
>     "band_2":13,
>     "band_3":13,
>     "band_4":13,
>     "band_5":13,
>     "band_6":13,
>     "band_7":13,
>     "band_8":13,
>     "maxpower_order":2,
>     "total_power":999
> }
> ```
>
> paddle_eigenvalue_1~4: 叶片特征值1~4
>
> point1~8: 关注点1~8速度谱能量
>
> band1~8: 关注带1~8速度谱能量
>
> maxpower_order: 速度谱最高能量点阶次
>
> total_power: 速度谱总能量



### 获取传感器的Z轴加速度频谱分析数据

> **获取传感器的Z轴关注点1~8, 关注带1~8加速度谱能量, 加速度谱最高能量点阶次, 加速度谱总能量**
>
> **获取传感器的Z轴加速度谱特征值**
>
> 寄存器: 103~123
>
> start: 103;	length: 2*21
>
> 指令:
>
> ``` json
> {
> 	"cmd":10
> }
> ```
>
> 返回值:
>
> ``` json
> {
>  	"res":0,
>  	"cmd":10,
> 	"fft_count":26,
>  	"channalID":3,
>  	"rotate_speed":20,
>     "inside_eigenvalue":26,
>  	"outside_eigenvalue":29,
>  	"roll_eigenvalue":20,
>     "shell_eigenvalue":13,
>     "point_1":10,
>     "point_2":10,
>     "point_3":10,
>     "point_4":10,
>     "point_5":10,
>     "point_6":10,
>     "point_7":10,
>     "point_8":10,
>     "band_1":13,
>     "band_2":13,
>     "band_3":13,
>     "band_4":13,
>     "band_5":13,
>     "band_6":13,
>     "band_7":13,
>     "band_8":13,
>     "maxpower_order":2,
>     "total_power":999
> }
> ```
>
> fft_count: 频谱分析周期计数
>
> channalID:振动通道ID
>
> rotate_speed:当前转速
>
> inside_eigenvalue: 内圈特征值1X -- 加速度谱
>
> outside_eigenvalue:外圈特征值
>
> roll_eigenvalue:滚动体特征值
>
> shell_eigenvalue: 保持架特征值
>
> point1~8: 关注点1~8加速度谱能量
>
> band1~8: 关注带1~8加速度谱能量
>
> maxpower_order: 最高能量点阶次
>
> total_power: 总能量



### 获取传感器的Z轴速度频谱分析数据

> **获取传感器的Z轴关注点1~8, 关注带1~8速度谱能量, 速度谱最高能量点阶次, 速度谱总能量**
>
> **获取传感器的Z轴速度谱特征值**
>
> 寄存器: 124~142
>
> start: 124;	length: 2*19
>
> 指令:
>
> ``` json
> {
> 	"cmd":11
> }
> ```
>
> 返回值:
>
> ``` json
> {
>  	"res":0,
>  	"cmd":11,
> 	"paddle_eigenvalue_1": 1,
>     "paddle_eigenvalue_2": 2,
>     "paddle_eigenvalue_3": 3,
>     "paddle_eigenvalue_4": 4,
>     "point_1":10,
>     "point_2":10,
>     "point_3":10,
>     "point_4":10,
>     "point_5":10,
>     "point_6":10,
>     "point_7":10,
>     "point_8":10,
>     "band_1":13,
>     "band_2":13,
>     "band_3":13,
>     "band_4":13,
>     "band_5":13,
>     "band_6":13,
>     "band_7":13,
>     "band_8":13,
>     "maxpower_order":2,
>     "total_power":999
> }
> ```
>
> paddle_eigenvalue_1~4: 叶片特征值1~4
>
> point1~8: 关注点1~8速度谱能量
>
> band1~8: 关注带1~8速度谱能量
>
> maxpower_order: 速度谱最高能量点阶次
>
> total_power: 速度谱总能量



### 获取传感器3个通道的诊断状态

> **重要, 诊断报警则说明工况异常**
>
> 寄存器: 143~149
>
> start: 143;   length: 2*7
>
> 指令:
>
> ``` json
> {
> 	"cmd":12
> }
> ```
>
> 返回值:
>
> ``` json
> {
>  	"res":0,
>  	"cmd":12,
> 	"channalx_status":0,
>     "channaly_status":1,
>     "channalz_status":0,
>     "temp_status":1,
>     "x_waring":0,
>     "y_waring":1,
>     "z_waring":0
> }
> ```
>
> channalx_status : 通道x的诊断状态 为1时处于警报状态
>
> temp_status: 温度震动预警报警状态 0正常1报警
>
> x_waring: x轴震动预警报警状态 0正常1报警



### 获取传感器版本号与序列号

> 寄存器: 150~151
>
> start: 150;   length: 2*2
>
> 指令:
>
> ``` json
> {
> 	"cmd":13
> }
> ```
>
> 返回值:
>
> ``` json
> {
>  	"res":0,
>  	"cmd":13,
> 	"version":12,
>     "license":211
> }
> ```
>
> version和license都以uint16_t的格式存储于寄存器中



### 获取传感器各个故障的特征参数

> 寄存器: 152~155
>
> start: 152;   length: 2*4
>
> 指令:
>
> ``` json
> {
> 	"cmd":14
> }
> ```
>
> 返回值:
>
> ``` json
> {
>  	"res":0,
>  	"cmd":14,
> 	"BPFI":12,
>     "BPFO":211,
>     "BSF":123,
>     "FTF":55
> }
> ```
>
> BPFI: 轴承内圈故障特征参数
>
> BPFO: 轴承外圈故障特征参数
>
> BSF: 轴承滚动体故障特征参数
>
> FTF: 轴承保持架故障特征参数



### 获取传感器的转速测量值与传动比

> 寄存器: 169~170
>
> start: 169;   length: 2*2
>
> 指令:
>
> ``` json
> {
> 	"cmd":15
> }
> ```
>
> 返回值:
>
> ``` json
> {
>  	"res":0,
>  	"cmd":15,
> 	"measue_speed":100,
> 	"proportion":50
> }
> ```
>
> measue_speed: 转速测量值(转/秒)
>
> proportion: 基础转速的比例系数



### 获取传感器各关注点的转频倍数与关注带起始+结束点转频倍数



## BLE控制端部分JSON指令

### 设定WiFi账号与密码

> 指令:
>
> ``` json
> {
>     "cmd": 1,
>     "ssid": "ssid1",
>     "psw": "12345678"
> }
> ```
>
> 返回值:
>
> ``` json
> {
>  	"res":0,
>  	"cmd":1,
> }
> ```
>
> **设置Wifi后，要进行连接尝试**



### 设定设备时区

> * 指令：
>
>   ```json
>   {
>       "cmd": 2,
>       "timezone": 8
>   }
>   ```
>
> 
>
> * 返回结果：
>
>   ```json
>   {
>       "res": 0,
>       "cmd": 2
>   }
>   ```



### 查询设备时区

> * 指令：
>
>   ```json
>   {
>       "cmd": 3
>   }
>   ```
>
> 
>
> * 返回结果：
>
>   ```json
>   {
>       "res": 0,
>       "cmd": 3,
>       "timezone": 8
>   }
>   ```



### 设定服务器url地址

> * 指令：
>
>   ```json
>   {
>       "cmd": 4,
>       "serverip": "192.168.5.101",
>       "serverport": 3001
>   }
>   ```
>
>   serverip：服务器域名或IP地址
>
>   serverport：服务器监听端口
>
> * 返回结果：
>
>   ```json
>   {
>       "res": 0,
>       "cmd": 4
>   }
>   ```



### 读取服务器设置

> * 指令：
>
>   ```json
>   {
>       "cmd": 5
>   }
>   ```
>
> * 返回结果：
>
>   ```json
>   {
>       "res": 0,
>       "cmd": 5,
>       "serverip": "192.168.5.101",
>       "serverport": 3001
>   }
>   ```



### 设置心跳包

> * 指令：
>
>   ```json
>   {
>       "cmd": 6,
>       "keepalivetime": 500,
>   }
>   ```
>
> * 返回结果：
>
>   ```json
>   {
>       "res": 0,
>       "cmd": 6
>   }
>   ```



### 读取心跳包

> * 指令：
>
>   ```json
>   {
>       "cmd": 7
>   }
>   ```
>
> * 返回结果：
>
>   ```json
>   {
>       "res": 0,
>       "cmd": 7,
>       "keepalivetime": 500
>   }
>   ```



### 配置传感器参数

> * 指令：
>
>   ```json
>   {
>       "cmd": 8,
>       "key":33
>   }
>   ```
>
> * 返回结果：
>
>   ```json
>   {
>       "res": 0,
>       "cmd": 8,
>   }
>   ```
>
>   **寄存器号为160**
>
>   **写入11保存当前参数(掉电不丢失)**
>
>   **写入22恢复出厂默认参数**
>
>   **写入33复位重启**
>
>   **写入44重置运行模式(修改的运行模式参数生效)**



### 修改传感器运行模式

> * 指令：
>
>   ```json
>   {
>       "cmd": 9,
>       "mode":1
>   }
>   ```
>
> * 返回结果：
>
>   ```json
>   {
>       "res": 0,
>       "cmd": 9,
>   }
>   ```
>
>   **寄存器号为161**
>
>   mode的取值范围为0~63 意义未知, 不要超出此范围



### 配置传感器modbus从机地址

> * 指令：
>
>   ```json
>   {
>       "cmd": 10,
>       "address":1
>   }
>   ```
>
> * 返回结果：
>
>   ```json
>   {
>       "res": 0,
>       "cmd": 10,
>   }
>   ```
>
>   **寄存器号为162**
>
>   address的取值范围为1~240



### 配置传感器串口波特率

> * 指令：
>
>   ```json
>   {
>       "cmd": 11,
>       "baudrate":3
>   }
>   ```
>
> * 返回结果：
>
>   ```json
>   {
>       "res": 0,
>       "cmd": 11,
>   }
>   ```
>
>   **寄存器号为163**
>
>   写入的值为1~9 对应波特率如下
>
>   [ 1] -2400
>
>   [ 2] -4800
>
>   [ 3] -9600
>
>   [ 4] -19200
>
>   [ 5] -38400
>
>   [ 6] -57600
>
>   [ 7] -115200
>
>   [ 8] -230400
>
>   [ 9] -460800



### 配置传感器速度高通截止频率

> * 指令：
>
>   ```json
>   {
>       "cmd": 12,
>       "speed_hpf":10
>   }
>   ```
>
> * 返回结果：
>
>   ```json
>   {
>       "res": 0,
>       "cmd": 12,
>   }
>   ```
>
>   **寄存器号为164**



### 配置传感器速度低通截止频率

> * 指令：
>
>   ```json
>   {
>       "cmd": 13,
>       "speed_lpf":10
>   }
>   ```
>
> * 返回结果：
>
>   ```json
>   {
>       "res": 0,
>       "cmd": 13,
>   }
>   ```
>
>   **寄存器号为165**



### 配置传感器加速度高通截止频率

> * 指令：
>
>   ```json
>   {
>       "cmd": 14,
>       "acc_hpf":10
>   }
>   ```
>
> * 返回结果：
>
>   ```json
>   {
>       "res": 0,
>       "cmd": 14,
>   }
>   ```
>
>   **寄存器号为166**



### 配置传感器加速度低通截止频率

> * 指令：
>
>   ```json
>   {
>       "cmd": 15,
>       "acc_lpf":10
>   }
>   ```
>
> * 返回结果：
>
>   ```json
>   {
>       "res": 0,
>       "cmd": 15,
>   }
>   ```
>
>   **寄存器号为167**



## 事件日志

> * 设备接收到相应指令或状态发生变化时，会分别通过蓝牙和Wifi向宿主机/服务器发送日志
>
> * 设备也会定时隔一段时间，分别通过蓝牙和Wifi向宿主机/服务器发送日志（心跳包）
>
> * 日志内容：
>
>   ```json
>   {
>       "cmd": 16/17,
>       "device_id": "xxxxxxx",
>       "blestatus": 1,
>       "wifistatus": 1,
>       "sysRuntime": 2975,
>       "time": "2023-10-01 12:00:00"
>   }
>   ```
>
>   cmd：事件类型。16——通过Wifi向服务器发送；17——通过蓝牙向宿主机发送
>
>   device_id：设备ID，一般为设备Mac地址（Wifi）组成的字符串
>
>   blestatus：蓝牙连接状态。0——未连接；1——已连接
>
>   wifistatus：Wifi连接状态。0——未连接；1——已连接
>
>   sysRuntime: 设备运行的时间, 可以改为"时/分/秒"制, 也可以单纯按秒
>
>   time：设备读取的世界时间
>



