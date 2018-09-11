//
//  HC_ChatParentViewController.h
//  HelpCrunchSDK
//
//  Created by Vlasov Illia on 7/13/17.
//  Copyright © 2017 Alex Kantaev. All rights reserved.
//

#import <UIKit/UIKit.h>

DEPRECATED_MSG_ATTRIBUTE("Use -HC_UserClosedChatNotification or -[HelpCrunch showFromController:delegate:]")
@interface HC_ChatParentViewController : UIViewController

- (void)donePressed;
- (void)imageAttachmentPressed:(NSString *)urlString;

@end
