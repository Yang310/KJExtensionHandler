//
//  KJCollectionVC.m
//  KJEmitterView
//
//  Created by 杨科军 on 2020/9/18.
//  Copyright © 2020 杨科军. All rights reserved.
//

#import "KJCollectionVC.h"
#import "UICollectionView+KJTouch.h"
@interface KJCollectionVC ()<UICollectionViewDelegate,UICollectionViewDataSource>
@property(nonatomic,strong)UICollectionView *collectView;
@property(nonatomic,strong)UIImageView *imageView;
@end

@implementation KJCollectionVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self.view addSubview:self.collectView];
    [self.view addSubview:self.imageView];
}
- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView*)collectionView{
    return 1;
}
- (NSInteger)collectionView:(UICollectionView*)collectionView numberOfItemsInSection:(NSInteger)section{
    return 10;
}
- (UICollectionViewCell*)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath{
    UICollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:@"item" forIndexPath:indexPath];
    cell.backgroundColor = [kRandomColor() colorWithAlphaComponent:0.9];
    return cell;
}
#pragma mark - UICollectionViewDelegateFlowLayout
- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath {
    return CGSizeMake(60, 60);
}
- (UIEdgeInsets)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout insetForSectionAtIndex:(NSInteger)section {
    return UIEdgeInsetsMake(10, 10, 10, 10);
}
- (UIImageView*)imageView{
    if (!_imageView) {
        _imageView = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, 60, 60)];
        _imageView.contentMode = UIViewContentModeScaleAspectFit;
        _imageView.hidden = YES;
        _imageView.layer.borderWidth = 2.;
        _imageView.layer.borderColor = UIColor.redColor.CGColor;
        _imageView.image = kGetImage(@"timg-2");
    }
    return _imageView;
}
- (UICollectionView*)collectView{
    if (_collectView == nil) {
        UICollectionViewFlowLayout *layOut = [[UICollectionViewFlowLayout alloc] init];
        [layOut setScrollDirection:UICollectionViewScrollDirectionHorizontal];
        layOut.minimumLineSpacing = 10;
        layOut.minimumInteritemSpacing = 10;
        _collectView = [[UICollectionView alloc] initWithFrame:CGRectMake(0, kScreenH-70, kScreenW, 70) collectionViewLayout:layOut];
        _collectView.delegate = self;
        _collectView.dataSource = self;
        _collectView.alwaysBounceHorizontal = YES;
        _collectView.showsHorizontalScrollIndicator = NO;
        _collectView.bounces = YES;
        _collectView.backgroundColor = [UIColor.greenColor colorWithAlphaComponent:0.3];
        [_collectView registerClass:[UICollectionViewCell class] forCellWithReuseIdentifier:@"item"];
        _collectView.kOpenExchange = true;
        _weakself;
        __block bool move = false;
        _collectView.moveblock = ^(KJMoveStateType state, CGPoint point) {
            if (point.y <= 60 && move == false) {
                move = true;
                point = [weakself.collectView convertPoint:point toView:kKeyWindow];
                NSIndexPath *idx = [weakself.collectView indexPathForItemAtPoint:point];
                UICollectionViewCell *nextCell = [weakself.collectView cellForItemAtIndexPath:idx];
                weakself.imageView.backgroundColor = nextCell.backgroundColor;
                weakself.imageView.center = point;
                weakself.imageView.hidden = NO;
            }else if (move && point.y < 60 && state == KJMoveStateTypeMove) {
                point = [weakself.collectView convertPoint:point toView:kKeyWindow];
                weakself.imageView.center = point;
                weakself.collectView.scrollEnabled = NO;
                return;
            }else if (state == KJMoveStateTypeEnd || state == KJMoveStateTypeCancelled) {
                move = false;
                point = [weakself.collectView convertPoint:point toView:kKeyWindow];
                weakself.imageView.center = CGPointZero;
                weakself.imageView.hidden = YES;
            }
            weakself.collectView.scrollEnabled = YES;
        };
    }
    return _collectView;
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
