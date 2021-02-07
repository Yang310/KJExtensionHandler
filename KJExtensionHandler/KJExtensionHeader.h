//
//  KJExtensionHeader.h
//  KJExtensionHandler
//
//  Created by 杨科军 on 2018/11/26.
//  Copyright © 2018 杨科军. All rights reserved.
//  https://github.com/yangKJ/KJExtensionHandler
//  从原先的KJEmitterView库当中分离出来的扩展工具库
/*
*********************************************************************************
*⭐️⭐️⭐️ ----- 本人其他库 ----- ⭐️⭐️⭐️
*
粒子效果、自定义控件、自定义选中控件
pod 'KJEmitterView'
pod 'KJEmitterView/Control' # 自定义控件
 
扩展库 - Button图文混排、点击事件封装、扩大点击域、点赞粒子效果，
手势封装、圆角渐变、倒影、投影、内阴影、内外发光、渐变色滑块等，
图片压缩加工处理、滤镜渲染、泛洪算法、识别网址超链接等等
pod 'KJExtensionHandler'
pod 'KJExtensionHandler/Foundation'
pod 'KJExtensionHandler/Language' # 多语言模块

播放器 - KJPlayer是一款视频播放器，AVPlayer的封装，继承UIView
视频可以边下边播，把播放器播放过的数据流缓存到本地，下次直接从缓冲读取播放
pod 'KJPlayer'  # 播放器功能区
pod 'KJPlayer/KJPlayerView'  # 自带展示界面

轮播图 - 支持缩放 多种pagecontrol 支持继承自定义样式 自带网络加载和缓存
pod 'KJBannerView'  # 轮播图，网络图片加载 支持网络GIF和网络图片和本地图片混合轮播

加载Loading - 多种样式供选择 HUD控件封装
pod 'KJLoading' # 加载控件

菜单控件 - 下拉控件 选择控件
pod 'KJMenuView' # 菜单控件
 
异常处理库 - 包含基本的防崩溃处理（数组，字典，字符串）
pod 'KJExceptionDemo'
 
Github地址：https://github.com/yangKJ
简书地址：https://www.jianshu.com/u/c84c00476ab6
博客地址：https://blog.csdn.net/qq_34534179
掘金地址：https://juejin.cn/user/1987535102554472/posts
邮箱地址：ykj310@126.com

* 如果觉得好用,希望您能Star支持,你的 ⭐️ 是我持续更新的动力!
*
*********************************************************************************
*/
#ifndef KJExtensionHeader_h
#define KJExtensionHeader_h

#import "_KJMacros.h" // 宏
#import "_KJINLINE.h" // 简单的常用函数
#import "_KJGCD.h"

#import "UIButton+KJBlock.h" // 点击事件ButtonBlock
#import "UIButton+KJEnlarge.h" // 改变UIButton的响应区域
#import "UIButton+KJContentLayout.h" // 图文混排
//#import "UIButton+KJIndicator.h" // 指示器
//#import "UIButton+KJEmitter.h" // 按钮粒子效果
//#import "UIButton+KJCountDown.h" // 倒计时

#import "UILabel+KJExtension.h" // 文本尺寸
//#import "UILabel+KJAttributedString.h" // 富文本

#import "UIView+KJXib.h" // Xib
#import "UIView+KJFrame.h" // Frame - 轻量级布局
#import "UIView+KJGestureBlock.h" // 手势Block
#import "UIView+KJRectCorner.h" // 切圆角
//#import "UIView+KJGradient.h" // 渐变处理 和 画指定图形（直线、虚线、五角星、六边形、八边形）

//#import "KJShadowLayer.h" // 内阴影、外阴影、投影相关
//#import "CALayer+KJReflection.h" // 倒影处理

#import "UINavigationBar+KJExtension.h" // 设置NavigationBar背景
#import "UINavigationItem+KJExtension.h" // 链式设置NavigationItem

//#import "UITextView+KJPlaceHolder.h" // 输入框扩展
//#import "UITextView+KJLimitCounter.h" // 限制字数
//#import "UITextView+KJHyperlink.h" // 超链接处理
//#import "UITextView+KJBackout.h" // 撤销输入

#import "UIImageView+KJLetters.h" // 头像浏览和文字头像
//#import "UIImageView+KJBlur.h" // 模糊处理

#import "UIScrollView+KJEmptyDataSet.h" // 没数据时状态

#import "UIColor+KJExtension.h" // 颜色相关扩展
#import "UIColor+KJExtension2.h"

#import "UIImage+KJScale.h" // 图片尺寸处理相关
#import "UIImage+KJCompress.h" // 图片压缩处理
#import "UIImage+KJMask.h" // 蒙版处理
#import "UIImage+KJJoint.h" // 图片拼接处理
#import "UIImage+KJCapture.h" // 截图和裁剪处理
#import "UIImage+KJCoreImage.h" // CoreImage 框架图片效果处理
#import "UIImage+KJAccelerate.h" // Accelerate  框架的图片处理
#import "UIImage+KJGIF.h" // 动态图相关
#import "UIImage+KJPhotoshop.h"
//#import "UIImage+KJFloodFill.h" // 图片泛洪算法
//#import "UIImage+KJURLSize.h" // 获取网络图片尺寸
//#import "UIImage+KJQRCode.h" // 二维码/条形码生成器

#import "UIViewController+KJFullScreen.h" // 充满全屏处理

//#import "UISegmentedControl+KJCustom.h" // 修改背景色和文字颜色

#import "UIScrollView+KJEmptyDataSet.h" // DZNEmptyDataSet 基础上再次封装没数据时状态

//#import "UICollectionView+KJTouch.h" // 获取Touch事件

//#import "KJColorSlider.h" // 渐变色滑块
//#import "UISlider+KJTapValue.h" // 滑杆点击改值

#import "UITextField+KJExtension.h" // 输入框扩展，快速设置账号密码框

#import "UIResponder+KJAdapt.h" // 简单的比例适配
#import "UIResponder+KJChain.h" // 响应链

//#import "KJMathEquation.h" // 数学方程式
//#import "KJGeometry.h" // 几何方程式
//#import "KJNodeQueue.h"// 栈操作工具
#import "NSObject+KJKVO.h" // 键值监听封装
#import "NSObject+KJSemaphore.h" // 信号方式解耦工具
#import "NSObject+KJRuntime.h" // runtime轻量级封装

#import "UIDevice+KJSystem.h" // 系统相关

//***************** 快捷创建UI *******************
#import "UIButton+KJCreate.h" // 快速创建按钮
#import "UILabel+KJCreate.h" // 快速创建文本

//************************************* Foundation 相关扩展 *****************************************
// 需要引入，请使用 pod 'KJExtensionHandler/Foundation'
#if __has_include(<KJExtensionHandler/_FoundartionHeader.h>)
#import <KJExtensionHandler/_FoundartionHeader.h>
#elif __has_include("_FoundartionHeader.h")
#import "_FoundartionHeader.h"
#else
#endif

//************************************* Language 多语言 *****************************************
// 需要引入，请使用 pod 'KJExtensionHandler/Language'
#if __has_include(<KJExtensionHandler/_KJLanguageHeader.h>)
#import <KJExtensionHandler/_KJLanguageHeader.h>
#elif __has_include("_KJLanguageHeader.h")
#import "_KJLanguageHeader.h"
#else
#endif

#endif /* KJExtensionHeader_h */
