//
//  NYHBaseViewController.m
//  StarrySky
//
//  Created by NYH on 14-9-25.
//  Copyright (c) 2014年 NYH. All rights reserved.
//

#import "NYHBaseViewController.h"

@interface NYHBaseViewController ()

@end

@implementation NYHBaseViewController

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
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    
    // 判断系统版本
    
    // 设置导航条背景图片
    [[UINavigationBar appearance]setBackgroundImage:[UIImage imageNamed:@"base.png"] forBarMetrics:UIBarMetricsDefault];
    
}

// 重写导航条标题
- (void)setTitle:(NSString *)title
{
    UILabel *titleLabel = [[UILabel alloc]init];
    [titleLabel setFrame:CGRectMake(0, 0, kScreenWidth, kNavigationBarHeight)];
    [titleLabel setBackgroundColor:[UIColor clearColor]];
    [titleLabel setFont:[UIFont systemFontOfSize:24.0f]];
    [titleLabel setTextColor:[UIColor whiteColor]];
    [titleLabel setTextAlignment:NSTextAlignmentCenter];
    [titleLabel setText:title];
    
    self.navigationItem.titleView = (UIView *)titleLabel;
}

// 设置状态栏内容颜色 Defaults to UIStatusBarStyleDefault
- (UIStatusBarStyle)preferredStatusBarStyle
{
    return UIStatusBarStyleLightContent;
}
- (BOOL)prefersStatusBarHidden
{
    return NO;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
