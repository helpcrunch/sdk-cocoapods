#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface HCSTheme : NSObject<NSCopying>

@property (nonatomic, strong) UIColor *mainColor;

@property (nonatomic, strong) UIColor *messageIncomingBubbleColor;
@property (nonatomic, strong) UIColor *messageIncomingFontColor;
@property (nonatomic, strong) UIColor *messageIncomingAgentNameFontColor;
@property (nonatomic, strong) UIColor *messageIncomingLinksColor;
@property (nonatomic, strong) UIColor *messageIncomingFileTypeBackgroundColor;
@property (nonatomic, strong) UIColor *messageIncomingFileTypeFontColor;

@property (nonatomic, strong) UIColor *messageOutgoingBubbleColor;
@property (nonatomic, strong) UIColor *messageOutgoingFontColor;
@property (nonatomic, strong) UIColor *messageOutgoingLinksColor;
@property (nonatomic, strong) UIColor *messageOutgoingFileTypeBackgroundColor;
@property (nonatomic, strong) UIColor *messageOutgoingFileTypeFontColor;

@property (nonatomic, strong) UIColor *messageDateColor;

@property (nonatomic, strong) UIImage *attachmentIconImage;
@property (nonatomic, strong) UIImage *sendButtonIconImage;

/**
 Default is null. On set Send button will use text instead of icon.
 */
@property (nonatomic, strong) NSString *sendButtonText;
@property (nonatomic, strong) UIColor *sendButtonColor;

@property (nonatomic, strong) UIColor *chatBackgroundColor;
@property (nonatomic, strong) UIColor *navigationBarTextColor;

@property (nonatomic, strong) UIColor *inputBackgroundColor;
@property (nonatomic, strong) UIColor *inputTextFieldBackgroundColor;
@property (nonatomic, strong) UIColor *inputTextFieldBorderColor;
@property (nonatomic, strong) UIColor *inputTextFieldPlaceholderColor;
@property (nonatomic, strong) UIColor *inputTextFieldFontColor;

@property (nonatomic, strong) NSString *startChatButtonText;
@property (nonatomic, strong) UIColor *startChatButtonColor;

@property (nonatomic) UIKeyboardAppearance keyboardAppearance;

@end

NS_ASSUME_NONNULL_END
