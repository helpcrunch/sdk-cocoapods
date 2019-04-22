#import "ViewController.h"

#import <HelpCrunchSDK/HelpCrunch.h>

@implementation ViewController

- (IBAction)buttonLaunchTouched:(id)sender {
    [HelpCrunch showFromController:self
                        completion:^(NSError * _Nullable error) {
                            NSLog(@"HelpCrunch is on screen");
                        }];
}

- (IBAction)buttonSetDefaultThemeTouched:(id)sender {
    [HelpCrunch bindTheme:[HelpCrunch defaultTheme]];
}

- (IBAction)buttonSetDarkThemeTouched:(id)sender {
    [HelpCrunch bindTheme:[HelpCrunch darkTheme]];
}

- (IBAction)buttonSetCustomThemeTouched:(id)sender {
    HCSTheme *theme = [HelpCrunch defaultTheme];
    
    theme.mainColor = [UIColor colorWithRed:0.38 green:0.84 blue:0.52 alpha:1.00];
    
    theme.sendButtonText = @"Hear me saying!";
    theme.sendButtonColor = [UIColor whiteColor];
    
    theme.chatBackgroundColor = [UIColor colorWithRed:0.22 green:0.30 blue:0.38 alpha:1.00];

    theme.messageIncomingBubbleColor = [UIColor colorWithRed:0.92 green:0.87 blue:0.68 alpha:1.00];
    theme.messageOutgoingBubbleColor = [UIColor colorWithRed:0.88 green:0.19 blue:0.19 alpha:1.00];
    
    theme.inputBackgroundColor = [UIColor colorWithRed:0.09 green:0.09 blue:0.15 alpha:1.00];
    theme.inputTextFieldBackgroundColor = [UIColor colorWithRed:0.30 green:0.30 blue:0.50 alpha:1.00];
    theme.inputTextFieldFontColor = [UIColor whiteColor];
    
    [HelpCrunch bindTheme:theme];
}

- (IBAction)buttonLogoutTouched:(id)sender {
    self.view.userInteractionEnabled = false;
    
    [self.logoutButton setTitle:@"Please wait" forState:UIControlStateNormal];
    
    [HelpCrunch logoutWithCompletion:^(NSError * _Nullable error) {
        self.view.userInteractionEnabled = true;
        
        [self.logoutButton setTitle:@"Logout" forState:UIControlStateNormal];
    }];
}

@end
