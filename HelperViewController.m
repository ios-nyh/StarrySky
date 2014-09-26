//
//  HelperViewController.m
//  CustomerOrder
//
//  Created by ios on 13-6-26.
//  Copyright (c) 2013年 hxhd. All rights reserved.
//

#import "HelperViewController.h"
#import "NYHHomeViewController.h"
#import "NYHBaseNavigationViewController.h"


#define NUM 4                             // 引导页数
#define kBtnWidth 160.0f                  //
#define kBtnHeight 40.0f                  //
#define kSystemTabbarHeight 49.0f         // 系统标签条高度
#define kMarge              6.0f

@interface HelperViewController () <UIScrollViewDelegate>

@end

@implementation HelperViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    UIScrollView *aScrollView = [[UIScrollView alloc]initWithFrame:[UIScreen mainScreen].bounds];
    aScrollView.contentSize = CGSizeMake(kScreenWidth * NUM, kScreenHeight);
    aScrollView.pagingEnabled = YES;
    aScrollView.showsHorizontalScrollIndicator = NO;
    aScrollView.delegate = self;
    [self.view addSubview:aScrollView];
    for (int i = 0; i < NUM; i++)
    {
        UIImageView *imgView = [[UIImageView alloc]initWithFrame:CGRectMake(kScreenWidth * i, 0, kScreenWidth, kScreenHeight)];
        [imgView setBackgroundColor:[UIColor whiteColor]];
        
        NSString *imgName = [NSString stringWithFormat:@"help_%d.png",i+1];
        [imgView setImage:[UIImage imageNamed:imgName]];
        [aScrollView addSubview:imgView];
    }
    
    // 屏幕适配
    UIButton *btn=[[UIButton alloc] initWithFrame:CGRectMake(kScreenWidth * (NUM-1) + (kScreenWidth-kBtnWidth)/2 , kScreenHeight - kSystemTabbarHeight - kBtnHeight*2 + kMarge, kBtnWidth , kBtnHeight)];
    [btn setTitle:@"点击进入" forState:UIControlStateNormal];
    [btn setTitleColor:[UIColor orangeColor] forState:UIControlStateNormal];
    btn.layer.borderWidth = 2;
    [aScrollView addSubview:btn];
    [btn addTarget:self action:@selector(removeHelper) forControlEvents:UIControlEventTouchUpInside];
}


#pragma mark - UIScrollViewDelegate

//- (void)scrollViewDidScroll:(UIScrollView *)scrollView
//{
//    float offset = scrollView.contentOffset.x / kScreenWidth;
//    if (offset > 1 && offset < NUM) {
//        self.view.alpha = NUM - offset;
//    }
//}
//
//- (void)scrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate
//{
//    float offset = scrollView.contentOffset.x / kScreenWidth;
//    if (offset > 1 && offset < NUM) {
//        [self removeHelper];
//    }
//}


// 进入主视图
- (void)removeHelper
{
    NYHHomeViewController *home = [[NYHHomeViewController alloc]init];
    NYHBaseNavigationViewController *homeNavi = [[NYHBaseNavigationViewController alloc]initWithRootViewController:home];
    
    [self presentViewController:homeNavi animated:YES completion:nil];
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
