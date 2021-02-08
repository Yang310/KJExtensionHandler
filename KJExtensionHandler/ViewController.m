//
//  ViewController.m
//  KJExtensionHandler
//
//  Created by 杨科军 on 2020/9/25.
//

#import "ViewController.h"
#import "KJHomeView.h"
#import "KJHomeModel.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.navigationController.navigationBar.kj_changeNavigationBarImage([UIImage imageNamed:@"timg-2"]).kj_changeNavigationBarTitle(UIColor.whiteColor,[UIFont boldSystemFontOfSize:20]);
    
    KJHomeModel *model = [KJHomeModel new];
    KJHomeView *view = [[KJHomeView alloc]initWithFrame:self.view.bounds];
    view.sectionTemps = model.sectionTemps;
    view.temps = model.temps;
    [self.view addSubview:view];
    
    _weakself;
    [view kj_receivedSemaphoreBlock:^id _Nullable(NSString * _Nonnull key, id _Nonnull message, id _Nullable parameter) {
        if ([key isEqualToString:kHomeViewKey]) {
            ((UIViewController*)message).title = ((NSDictionary*)parameter)[@"describeName"];
            [weakself.navigationController pushViewController:message animated:true];
        }
        return nil;
    }];
    
    self.navigationController.navigationBar.kj_changeNavigationBarImage([UIImage imageNamed:@"timg-2"]).kj_changeNavigationBarTitle(UIColor.whiteColor,[UIFont boldSystemFontOfSize:20]);
}

@end
