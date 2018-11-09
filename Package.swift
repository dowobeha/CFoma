// swift-tools-version:4.2

import PackageDescription

let package = Package(
  name: "CFoma",
  products: [
    // Products define the executables and libraries produced by a package, and make them visible to other packages.
    .library(
      name: "CFoma",
      targets: ["CFoma"]),
  ],
  dependencies: [],
  targets: [ .systemLibrary(name: "CFoma", path: ".") ]

)


//    umbrella header "include/CFoma.h"
