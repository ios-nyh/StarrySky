//
//  NYHAppDelegate.m
//  StarrySky
//
//  Created by NYH on 14-9-25.
//  Copyright (c) 2014年 NYH. All rights reserved.
//

#import "NYHAppDelegate.h"
#import "NYHHomeViewController.h"
#import "NYHBaseNavigationViewController.h"
#import "HelperViewController.h"

@implementation NYHAppDelegate

@synthesize homeViewController = _homeViewController;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    // Override point for customization after application launch.
    
    // 判断网络
    
    
    // 加载视图
    [self addHelperView];
    
    // 控制状态条iOS6和iOS7，白色内容
    [[UIApplication sharedApplication]setStatusBarStyle:UIStatusBarStyleLightContent];
    
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];
    
    return YES;
}

// 加载引导视图
- (void)addHelperView
{
    NSString *docPath = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0];
    NSString *path = [docPath stringByAppendingPathComponent:@"Helper"];
    NSFileManager *fm = [NSFileManager defaultManager];
    // 测试 NO 暂时改为 YES
    if ([fm fileExistsAtPath:path] == YES) {
        [fm createDirectoryAtPath:path withIntermediateDirectories:YES attributes:nil error:nil];
        HelperViewController *helper = [[HelperViewController alloc]init];
        [self.window setRootViewController:helper];
    } else {
        [self addHomeViewController];
    }
}

// 加载主视图
- (void)addHomeViewController
{
    NYHHomeViewController *home = [[NYHHomeViewController alloc]init];
    NYHBaseNavigationViewController *navi = [[NYHBaseNavigationViewController alloc]initWithRootViewController:home];
    self.window.rootViewController = navi;
}


- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
