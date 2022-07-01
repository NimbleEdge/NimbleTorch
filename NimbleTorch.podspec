#
# Be sure to run `pod lib lint NimbleTorch.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'NimbleTorch'
  s.version          = '0.1.0'
  s.summary          = 'A short description of NimbleTorch.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/NimbleEdge/NimbleTorch'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'Apache 2.0', :file => 'LICENSE' }
  s.author           = { 'noreply' => 'noreply@gmail.com' }
  s.source           = { :git => 'https://github.com/NimbleEdge/NimbleTorch.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  
  s.ios.deployment_target = '13.0'
  s.default_subspec = 'Core'
    s.subspec 'Core' do |ss|
        ss.dependency 'NimbleTorch/Torch'
        ss.source_files = 'src/*.{h,cpp,c,cc}'
        ss.public_header_files = ['src/LibTorch.h']
    end
  s.subspec 'Torch' do |ss|
        ss.header_mappings_dir = 'install/include/'
        ss.preserve_paths = 'install/include/**/*.{h,cpp,cc,c}'
        ss.vendored_libraries = 'install/lib/*.a'
        ss.libraries = ['c++', 'stdc++']
    end
  s.user_target_xcconfig = {
        'HEADER_SEARCH_PATHS' => '$(inherited) "/Users/ayushb/tmp/NimbleTorch/install/include/"',
        'OTHER_LDFLAGS' => '-force_load "/Users/ayushb/tmp/NimbleTorch/install/lib/libtorch.a" -force_load "/Users/ayushb/tmp/NimbleTorch/install/lib/libtorch_cpu.a"',
        'CLANG_CXX_LANGUAGE_STANDARD' => 'c++14',
        'CLANG_CXX_LIBRARY' => 'libc++'
    }
  s.pod_target_xcconfig = {
        'HEADER_SEARCH_PATHS' => '$(inherited) "/Users/ayushb/tmp/NimbleTorch/install/include/"',
        'VALID_ARCHS' => 'arm64',
	'ENABLE_BITCODE' => 'YES' 

    }
  s.library = ['c++', 'stdc++']

  
  # s.resource_bundles = {
  #   'NimbleTorch' => ['NimbleTorch/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
