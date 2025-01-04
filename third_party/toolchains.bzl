load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def load_toolchains():
    if "com_github_tvsc_arm-none-eabi-gcc-11.3.1" not in native.existing_rules():
        http_archive(
            name = "com_github_tvsc_arm-none-eabi-gcc-11.3.1",
            sha256 = "8470c924f6f4ea7a25d749339b29ffdb7fd0bf7bfc797a42fc0f6c26123bbb35",
            urls = [
                "https://github.com/stellarcorp/arm-none-eabi-gcc-11.3.1/archive/4cb8d0a60a1a22e7585ca0ba9bd74d3422c0922e.tar.gz",
            ],
            strip_prefix = "arm-none-eabi-gcc-11.3.1-4cb8d0a60a1a22e7585ca0ba9bd74d3422c0922e",
        )
