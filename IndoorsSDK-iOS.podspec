Pod::Spec.new do |s|
   s.name                    = "IndoorsSDK-iOS"
   s.version                 = "3.0.1"
   s.platform                = :ios, "7.0"
   s.summary                 = "iOS SDK for performing indoors mapping and localisation provided by indoo.rs"
   s.authors                 = { "indoo.rs"  => "office@indoo.rs" }
   s.homepage                = "https://github.com/customlbs/IndoorsSDK-iOS"
   s.license                 = { :type => "Copyright",
                                 :text => "Copyright 2015 indoo.rs GmbH. All rights reserved." }
   s.source                  = { :git => "https://github.com/customlbs/IndoorsSDK-iOS.git", 
   								 :tag => "3.0.1" }

								
   s.ios.vendored_frameworks = "Indoors.framework", "IndoorsSurface.framework"
   
   s.ios.frameworks          = "QuartzCore", "SystemConfiguration", "CoreMotion", "CFNetwork", "UIKit", 							   "Foundation", "CoreBluetooth", "CoreGraphics", "CoreLocation"
   
   s.libraries 				 = "z", "sqlite3.0", "c++"
   
   s.requires_arc            = true

 end
