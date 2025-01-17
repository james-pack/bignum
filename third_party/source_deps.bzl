load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def load_source_dependencies():
    if not native.existing_rule("bazel_skylib"):
        http_archive(
            name = "bazel_skylib",
            urls = [
                "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/1.2.1/bazel-skylib-1.2.1.tar.gz",
                "https://github.com/bazelbuild/bazel-skylib/releases/download/1.2.1/bazel-skylib-1.2.1.tar.gz",
            ],
            sha256 = "f7be3474d42aae265405a592bb7da8e171919d74c16f082a5457840f06054728",
        )

    if not native.existing_rule("rules_cc"):
        http_archive(
            name = "rules_cc",
            strip_prefix = "rules_cc-2f8c04c04462ab83c545ab14c0da68c3b4c96191",
            sha256 = "4aeb102efbcfad509857d7cb9c5456731e8ce566bfbf2960286a2ec236796cc3",
            urls = [
                "https://github.com/bazelbuild/rules_cc/archive/2f8c04c04462ab83c545ab14c0da68c3b4c96191.tar.gz",
            ],
        )

    if not native.existing_rule("rules_proto"):
        http_archive(
            name = "rules_proto",
            sha256 = "dc3fb206a2cb3441b485eb1e423165b231235a1ea9b031b4433cf7bc1fa460dd",
            strip_prefix = "rules_proto-5.3.0-21.7",
            urls = [
                "https://github.com/bazelbuild/rules_proto/archive/refs/tags/5.3.0-21.7.tar.gz",
            ],
        )

    if not native.existing_rule("rules_pkg"):
        http_archive(
            name = "rules_pkg",
            urls = [
                "https://mirror.bazel.build/github.com/bazelbuild/rules_pkg/releases/download/0.7.0/rules_pkg-0.7.0.tar.gz",
                "https://github.com/bazelbuild/rules_pkg/releases/download/0.7.0/rules_pkg-0.7.0.tar.gz",
            ],
            sha256 = "8a298e832762eda1830597d64fe7db58178aa84cd5926d76d5b744d6558941c2",
        )

    if not native.existing_rule("io_bazel_rules_docker"):
        http_archive(
            name = "io_bazel_rules_docker",
            sha256 = "b1e80761a8a8243d03ebca8845e9cc1ba6c82ce7c5179ce2b295cd36f7e394bf",
            urls = ["https://github.com/bazelbuild/rules_docker/releases/download/v0.25.0/rules_docker-v0.25.0.tar.gz"],
        )

    if not native.existing_rule("com_google_googletest"):
        http_archive(
            name = "com_google_googletest",
            sha256 = "3c2a0999fb9f85423d17e3000b339fd28501433f70c2e9941c8e784ac8624a10",
            strip_prefix = "googletest-cead3d57c93ff8c4e5c1bbae57a5c0b0b0f6e168",
            urls = ["https://github.com/google/googletest/archive/cead3d57c93ff8c4e5c1bbae57a5c0b0b0f6e168.zip"],
        )

    if not native.existing_rule("com_github_google_benchmark"):
        http_archive(
            name = "com_github_google_benchmark",
            sha256 = "8a63c9c6adf9e7ce8d0d81f251c47de83efb5e077e147d109fa2045daac8368b",
            strip_prefix = "benchmark-1.9.1",
            urls = ["https://github.com/google/benchmark/archive/v1.9.1.zip"],
        )

    if not native.existing_rule("com_github_gflags_gflags"):
        http_archive(
            name = "com_github_gflags_gflags",
            sha256 = "34af2f15cf7367513b352bdcd2493ab14ce43692d2dcd9dfc499492966c64dcf",
            strip_prefix = "gflags-2.2.2",
            urls = ["https://github.com/gflags/gflags/archive/v2.2.2.tar.gz"],
        )

    if not native.existing_rule("com_github_google_glog"):
        http_archive(
            name = "com_github_google_glog",
            sha256 = "21bc744fb7f2fa701ee8db339ded7dce4f975d0d55837a97be7d46e8382dea5a",
            urls = ["https://github.com/google/glog/archive/v0.5.0.zip"],
            strip_prefix = "glog-0.5.0",
        )

    if not native.existing_rule("zlib"):
        http_archive(
            name = "zlib",
            sha256 = "1525952a0a567581792613a9723333d7f8cc20b87a81f920fb8bc7e3f2251428",
            strip_prefix = "zlib-1.2.13",
            urls = [
                "https://github.com/madler/zlib/archive/refs/tags/v1.2.13.tar.gz",
            ],
            build_file = "//third_party/zlib:zlib.BUILD",
        )
