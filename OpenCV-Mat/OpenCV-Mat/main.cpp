//
//  main.cpp
//  OpenCV-Mat
//
//  Created by 陈江林 on 2019/9/8.
//  Copyright © 2019 陈江林. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
using namespace std;
using namespace cv;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    // Mat 对象OPenCV2.0之后引进的图像树结构、自动分配内存、不存在内存泄漏的问题，是面向对象的数据结构。分成两个部分，头部与数据部分
    // 常用的方法：
    // void copyTo(Mat mat)
    // void converTo(Mat dst, int type)
    // Mat clone()
    // int channels()
    // int depth()
    // bool empty()
    // uchar *ptr(i=0)
    
    string imagePath = "/Users/chenjianglin/Documents/C++/OpenCV04/OpenCV-Mat/Source/tupian.jpg";
    Mat image = imread(imagePath);
    if (image.empty()) {
        cout << "图片加载失败" << endl;
        return -1;
    }
    string inputWindow = "inputWindow";
    namedWindow(inputWindow);
    imshow(inputWindow, image);
    /// mat 初始化 创建一张空白的图像
    /*
    Mat dst;
    dst = Mat(image.size(), image.type());
    dst = Scalar(127, 0, 255);
     */
    // 克隆 完全copy
    /*
    Mat dst;
    dst = image.clone();
     */
    // copy
    /*
    Mat dst;
    image.copyTo(dst);
     */
    // 复制操作以及拷贝构造函数只会复制头部分
    // 使用cone 以及 copyto会完全复制
    // Scalar 参数是向量表示初始化每个像素值是多少
    
    Mat dst;
    cvtColor(image, dst, COLOR_BGR2GRAY);
    
    cout << "image.channels =" << image.channels() << endl;
    cout << "dst.channels =" << dst.channels() << endl;
    
    const uchar *firstValues = dst.ptr<uchar>(0);
    
    cout << *firstValues << endl;
    
    Mat M = Mat(3, 3, CV_8UC3, Scalar(0, 0, 255));
    
    cout << M << endl;
    
    // 通过create方式进行创建
    Mat m1;
    m1.create(3, 3, CV_8UC3);
    m1 = Scalar(0, 0, 255);
    // 掩膜初始化
    Mat kernel = (Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    // 所有的对象都初始化成0
    Mat zeros = Mat::zeros(image.size(), image.type());
    
    Mat m2 = Mat::zeros(2, 2, CV_8UC1);
    
    Mat m3 = Mat::eye(2, 2, CV_8UC1);
    
    string outWindow = "outPutWindow";
    namedWindow(outWindow);
    imshow(outWindow, dst);
    
    
    waitKey(0);
    return 0;
}
