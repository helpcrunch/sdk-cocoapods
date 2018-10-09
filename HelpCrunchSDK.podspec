Pod::Spec.new do |spec|
spec.name = "HelpCrunchSDK"
spec.version = "1.1.00"
spec.summary = "A perfect live chat, email automation and a super-intuitive help desk in one smart customer communication platform."
spec.documentation_url = 'https://docs.helpcrunch.com/ios-sdk.html'
spec.homepage = "https://github.com/helpcrunch/sdk-cocoapods"
spec.license = { type: 'Apache 2.0', file: 'LICENSE' }
spec.authors = { "Illia Vlasov" => 'vlasovia@gmail.com' }
#spec.module_name = 'HelpCrunchSDK'

spec.frameworks = 'SystemConfiguration', 'AudioToolbox' #add UserNotifications?

spec.ios.deployment_target = '10.0'
spec.requires_arc = true
#spec.static_framework = true
spec.source = { :git => "https://github.com/helpcrunch/sdk-cocoapods.git", :tag => "#{spec.version}", :branch => "dev"}

#spec.source_files = "HelpCrunchSDK.framework/Versions/A/Headers/*.h"
spec.public_header_files = 'HelpCrunchSDK.framework/Versions/A/Headers/*.h'
spec.vendored_frameworks  = 'HelpCrunchSDK.framework'
spec.resources = 'HelpCrunchSDK.bundle'
spec.xcconfig            = {
    'FRAMEWORK_SEARCH_PATHS' => '$(inherited) ${PODS_ROOT}/HelpCrunchSDK/',
}

spec.dependency 'Socket.IO-Client-Swift', '~> 13.3.0'


end

