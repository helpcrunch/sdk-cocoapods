
# HelpCrunch SDK

A perfect live chat, email automation and a super-intuitive help desk in one smart customer communication platform.

## Installation

### Installation with [CocoaPods](https://cocoapods.org)

CocoaPods is a dependency manager for Swift and Objective-C Cocoa projects. It has over 43 thousand libraries and is used in over 3 million apps. CocoaPods can help you scale your projects elegantly.

CocoaPods is built with Ruby and is installable with the default Ruby available on OS X. We recommend you use the default ruby.

Using the default Ruby install can require you to use  `sudo`  when installing gems. Further installation instructions are in  [the guides](https://guides.cocoapods.org/using/getting-started.html#getting-started).

```
$ sudo gem install cocoapods
```

There is also  [Mac app](https://cocoapods.org/app)  for CocoaPods. It only gets major releases ATM though.

#### Podfile

To integrate HelpCrunch into your Xcode project using CocoaPods, specify it in your  `Podfile`(text file named `Podfile` in your Xcode project directory):

```
use_frameworks!

target 'ProjectTargetName' do
  pod 'HelpCrunchSDK'
end
```

> Tip: CocoaPods provides a `pod init` command to create a Podfile with smart defaults. You should use it.


Now you can install the dependencies in your project:

```
$ pod install
```

Make sure to always open the Xcode workspace instead of the project file when building your project:

```
$ open App.xcworkspace
```

Now you can import your dependencies e.g.:

```
#import <HelpCrunchSDK/HelpCrunch.h> // Objective C
import HelpCrunchSDK // Swift
```
### Manual installation

[HelpCrunch SDK Documentation](https://docs.helpcrunch.com/ios-sdk.html)

## Documentation

Documentation is [available here](https://docs.helpcrunch.com/ios-sdk.html)

## License

This project is licensed under the Apache License 2.0 - see the [LICENSE](LICENSE) file for details
