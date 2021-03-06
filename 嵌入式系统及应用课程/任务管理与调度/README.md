# Embedded-Engineer
> 关于嵌入式系统及应用上课总结（PPT抄一遍）

## 嵌入式硬件系统

#### 任务管理与调度
##### 任务概述
    * 进程由代码、数据、堆栈和进程控制模块构成

  使用线程优势：
    * 在一个已有进程中创建一个线程比创建一个全新的进程开销小；
    * 终止时间少
    * 切换花费的时间少
    * 通信：使同一进程内部不同线程之间的通信效率得到显著提高。

  大多数嵌入式实时内核：单进程多线程模型，或成为任务模型

  任务是嵌入式操作系统内核的基本调度单位，任务主要包含以下内容：
    * 代码
    * 数据
    * 堆栈
    * 程序执行上下文环境

  任务通常包含一个具有无限循环的程序，任务的特性：
    * 动态性，一般分为就绪态、运行态、和等待态
    * 并发成并行性，系统中同时存在多个任务，宏观上是同时运行的
    * 异步独立性，每个任务按照自己相互独立的不可预知的速度运行，走走停停

  采用多任务的好处：
    * 任务的规模较小，分层，每个任务更容易编码和调试，质量更容易得到保证
    * 任务之间具有较高的独立性，耦合性小
    * 实时性强

  任务的分类：
    * 按到达情况的可预测性分为周期性和非周期性任务
    * 按重要程度划分可分为关键任务和非关键任务

  任务参数：
    * 优先级  表示任务对应工作内容处理上的优先程度
      > uCos II 共可管理64个任务，每个任务必须有不同的优先级，最低优先级被系统保留
      > uCos III 已经可以支持同一优先级有多个任务，且可以自行设置优先级的个数
    * 周期  表示任务周期性执行的时间间隔
    * 任务的计算时间，在特定硬件环境下被完整执行所需要的时间，通常用最坏的情况下执行时间
    * 任务的就绪时间
    * 任务的截止时间
      > 截止时间可以通过绝对时间和相对时间来表示。相对时间为任务的绝对时间减去任务的就绪时间
      > 截止时间可以分为强截止时间和弱截止时间
      > 具有强截止时间的任务即为关键任务，若截止时间不能得到满足，出现严重后果
      > 拥有关键任务的实时系统又称为强实时系统，后者为弱实时系统




