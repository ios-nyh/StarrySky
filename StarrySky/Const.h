//
//  Const.h
//  StarrySky
//
//  Created by NYH on 14-9-25.
//  Copyright (c) 2014年 NYH. All rights reserved.
//

#ifndef StarrySky_Const_h
#define StarrySky_Const_h

/**
 *  物理屏幕大小
 */
#define kScreenWidth   [UIScreen mainScreen].bounds.size.width
#define kScreenHeight  [UIScreen mainScreen].bounds.size.height

// 导航条高度
#define kNavigationBarHeight 44.0f
// 状态条高度
#define kStatusBarHeight     20.0f
// 导航条和状态条总高度
#define kTopHeight           64.0f

// 判断系统版本 iOS6 和 iOS7，以后增加iOS8
#define AT_LEAST_IOS7   ([[[UIDevice currentDevice] systemVersion] compare:@"7.0"] != NSOrderedAscending)

// 判断设备版本 iPhone480、iPhone568、iPhone。。。（iPhone6/Plus）
#define iPhone568 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640.0, 1136.0), [[UIScreen mainScreen] currentMode].size) : NO)



/**
 *  宏定义调试
 */
#ifdef DEBUG
#   define DLog(fmt, ...) {NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);}
#   define ELog(err) {if(err) DLog(@"%@", err)}
#else
#   define DLog(...)
#   define ELog(err)
#endif
// ALog always displays output regardless of the DEBUG setting
#define ALog(fmt, ...) {NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);};

// RGB颜色设置
#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]


#define kRGB(r,g,b) [UIColor colorWithRed:r/255. green:g/255. blue:b/255. alpha:1]
#define kBlueColor [UIColor colorWithRed:62/255. green:171/255. blue:250/255. alpha:1]
#define kBackGroudColor [UIColor colorWithRed:245/255. green:245/255. blue:245/255. alpha:1]
#define kOrangeColor [UIColor orangeColor]
#define kCellBackGroundColor [UIColor colorWithRed:236/255. green:236/255. blue:236/255. alpha:1]
//172.16.1.142

#define kNULL [NSNull null]
#define LOCALHOST 0  //1 是本地 0 是外部
//#define DEBUG 0 //调试模式 1  发布 0
#define NLog 0



#define KAliPayAppScheme @"ali.zsdp"


#define SGALERT_SHOW(msg) [SGInfoAlert showInfo:msg bgColor:[UIColor orangeColor].CGColor inView:self.view vertical:.7]

#if LOCALHOST
#define kHOST @"http://192.168.1.110:8080"
#else
#define kHOST @"http://www.zhangshangdianpu.com"
#endif

//#if LOCALHOST
#define kURLHost kHOST
#define kURLShopListImage [kHOST stringByAppendingString:@"/Uploads/Editor/"]
//http://localhost/onethink/Home/Api/addAppraise
//#else
//#define kURLHost @"http://172.16.1.142/onethink/Uploads/Editor"
//#define kURLShopListImage @"http://172.16.1.142/onethink/Uploads/Editor"
//#endif


// 读取缓存路径
#define kSubInfoFile [NSHomeDirectory() stringByAppendingPathComponent:@"Library/Caches/subinfo.lrs"]
#define kShopFile [NSHomeDirectory() stringByAppendingPathComponent:@"Library/Caches/shop.lrs"]
#define kShoucanglistFile [NSHomeDirectory() stringByAppendingPathComponent:@"Library/Caches/shoucanglist.lrs"]
#define kCatlistFile [NSHomeDirectory() stringByAppendingPathComponent:@"Library/Caches/catlist.lrs"]



#define myDotNumbers  @"0123456789.\n"
#define myNumbers     @"0123456789\n"

/**** USERDEFAULT ****/
#define USERDEFAULT_SAVE(value,key)  [[NSUserDefaults standardUserDefaults] setValue:value forKey:key]
#define USERDEFAULT_GET(key) [[NSUserDefaults standardUserDefaults] valueForKey:key]
#define USERDEFAULT_SYNC [[NSUserDefaults standardUserDefaults] synchronize]
#define USERDEFAULT_REMOVE(key) [[NSUserDefaults standardUserDefaults] removeObjectForKey:key]

#define NOTIFICATION_ADD_OBSERVER(nobserver,nselector,nname,nobject)  [[NSNotificationCenter defaultCenter] addObserver:nobserver selector:@selector(nselector) name:nname object:nobject]
#define NOTIFICATION_REMOVE_ALL [[NSNotificationCenter defaultCenter] removeObserver:self]
#define NOTIFICATION_POST(name,obj,userinfo) [[NSNotificationCenter defaultCenter] postNotificationName:name object:obj userInfo:userinfo]
#define NOTIFICATION_REMOVE(nm) [[NSNotificationCenter defaultCenter] removeObserver:self name:nm object:nil]

#define UNARCHIVER_FILE(filePath) [NSKeyedUnarchiver unarchiveObjectWithFile:filePath]


#define DATE_SINCE_1970(time) [NSDate dateWithTimeIntervalSince1970:time]
#define DATEFORMATTER_INIT [[NSDateFormatter alloc] init]
#define DATEFORMATTER_SET_YYmmDD_HHmmSS(formatter) [formatter setDateFormat:@"yyyy/MM/dd HH:mm:ss"]
#define DATEFORMATTER_GET_STRING(formatter,date) [formatter stringFromDate:date]

#define STRING_SIZE(str,font,csize) [str sizeWithFont:font constrainedToSize:csize lineBreakMode:NSLineBreakByWordWrapping];

#define VIEW_INIT [[UIView alloc] init]
#define VIEW_INIT_FRAME(x,y,w,h) [[UIView alloc] initWithFrame:CGRectMake(x,y,w,h)]

#define SCROLLVIEW_INIT [[UIScrollView alloc] init]
#define BUTTON_CUSTOM [UIButton buttonWithType:UIButtonTypeCustom]
#define BUTTON_ADD_ACTION(button,sel) [button addTarget:self action:@selector(sel) forControlEvents:UIControlEventTouchUpInside]
#define BUTTON_SET_TITLE_NOMAL(button,title) [button setTitle:title forState:UIControlStateNormal]
#define BUTTON_SET_TITLECOLOR_NOMAL(button,color) [button setTitleColor:color forState:UIControlStateNormal]
#define BUTTON_SET_BACKGROUND_IMAGE_NOMAL(button,imageName) [button setBackgroundImage:[UIImage imageNamed:imageName] forState:UIControlStateNormal]
#define BUTTON_SET_IMAGE_NOMAL(button,imageName) [button setImage:[UIImage imageNamed:imageName]forState:UIControlStateNormal]

#define SEARCHBAR_INIT_FRAME(x,y,w,h) [[UISearchBar alloc] initWithFrame:CGRectMake(x, y, w, h)]

#define CELL_DEQUEUERESUABLE_IDNETIFIER(identifier) [tableView dequeueReusableCellWithIdentifier:identifier]

#define LABEL_INIT_FRAME(x,y,w,h) [[UILabel alloc] initWithFrame:CGRectMake(x, y, w, h)]
#define IMAGEVIEW_INIT  [[UIImageView alloc] init]
#define IMAGEVIEW_SET_IMAGE(imageView,image) [imageView setImage:image]

#define IMAGEVIEW_SET_IMAGE_NAMED(imageview,name) [imageview setImage:IMAGE_NAMED(name)]
#define IMAGE_NAMED(name) [UIImage imageNamed:name]

#define PRESENT_VC(controller,animation,com) [self presentViewController:controller animated:animation completion:com]
#define DISMISS_PRESENT(animation,com) [self dismissViewControllerAnimated:animation completion:com]

#define TABLEVIEWCELL_DEFAULT(identifier) [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier]
#define TABLEVIEW_INIT [[UITableView alloc] init]

#define FONT_SYSTEM(x) [UIFont systemFontOfSize:x]
#define FONT_BOLD(x) [UIFont boldSystemFontOfSize:x]
#define FONT_NAME(name,fsize) [UIFont fontWithName:name size:fsize]

#define MUTABLEARRAY_ARRAY [NSMutableArray array]
#define HUD_SHOW  HUD=[[MBProgressHUD alloc] initWithView:self.view];[self.view addSubview:HUD];[HUD show:YES]
#define HUD_HIDE [HUD hide:YES];[HUD removeFromSuperview]
#define NUMBER_NSINTEGER(integer) [NSNumber numberWithInteger:integer]

/**** 颜色 ****/
#define kCOLOR_BLACK [UIColor blackColor]
#define kCOLOR_DARKGRAY [UIColor darkGrayColor]
#define kCOLOR_LIGHTGRAY [UIColor lightGrayColor]
#define kCOLOR_WHITE [UIColor whiteColor]
#define kCOLOR_GRAY [UIColor grayColor]
#define kCOLOR_RED [UIColor redColor]
#define kCOLOR_GREEN [UIColor greenColor]
#define kCOLOR_BLUE [UIColor blueColor]
#define kCOLOR_CYAN [UIColor cyanColor]
#define kCOLOR_YELLOW [UIColor yellowColor]
#define kCOLOR_MAGENTA [UIColor magentaColor]
#define kCOLOR_ORANGE [UIColor orangeColor]
#define kCOLOR_PURPLE [UIColor purpleColor]
#define kCOLOR_BROWN [UIColor brownColor]
#define kCOLOR_CLEAR [UIColor clearColor]


#endif
