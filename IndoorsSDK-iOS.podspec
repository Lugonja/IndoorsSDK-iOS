Pod::Spec.new do |s|
   s.name                    = "IndoorsSDK-iOS"
   s.version                 = "4.0.2"
   s.platform                = :ios, "7.1"
   s.summary                 = "iOS SDK for performing indoors mapping and localisation provided by indoo.rs"
   s.authors                 = { "indoo.rs"  => "office@indoo.rs" }
   s.homepage                = "http://www.indoo.rs"
   s.documentation_url       = "http://indoors.readme.io/docs/getting-started-with-indoors-ios-sdk"
   s.license                 = { :type => "Copyright",
                                 :text => "Copyright 2015 indoo.rs GmbH. All rights reserved." }
   s.source                  = { :git => "https://bitbucket.org/indoors/indoorssdk-ios.git", 
   								      :tag => "4.0.2" }

								
   s.ios.vendored_frameworks = "IndoorsSDK.framework"
   
   s.ios.frameworks          = "QuartzCore", "SystemConfiguration", "CoreMotion", "CFNetwork", "UIKit", "Foundation", "CoreBluetooth", "CoreGraphics", "CoreLocation"
   
   s.libraries               = "z", "sqlite3.0", "c++"
   
   s.requires_arc            = true

 end
