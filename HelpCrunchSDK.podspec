Pod::Spec.new do |spec|
spec.name = "HelpCrunchSDK"
spec.version = "1.0.47"
spec.summary = "A perfect live chat, email automation and a super-intuitive help desk in one smart customer communication platform."
spec.documentation_url = 'https://docs.helpcrunch.com/ios-sdk.html'
spec.homepage = "https://github.com/helpcrunch/sdk-cocoapods"
spec.license = { type: 'Apache 2.0', file: 'LICENSE' }
spec.authors = { "Illia Vlasov" => 'vlasovia@gmail.com' }

spec.frameworks = 'SystemConfiguration', 'JavaScriptCore', 'AudioToolbox' #add UserNotifications?

spec.platform = :ios, "8.0"
spec.requires_arc = true
spec.source = { :git => "https://github.com/helpcrunch/sdk-cocoapods.git",
                :tag => "#{spec.version}",
                :branch => "legacy"
}

spec.source_files = "HelpCrunchSDK.framework/Versions/A/Headers/*.h"
spec.public_header_files = 'HelpCrunchSDK.framework/Versions/A/Headers/*.h'
spec.vendored_frameworks  = 'HelpCrunchSDK.framework'
spec.resources = 'HelpCrunchSDK.bundle'
spec.xcconfig            = {
'FRAMEWORK_SEARCH_PATHS' => '"${PODS_ROOT}/HelpCrunchSDK"',
}


end

