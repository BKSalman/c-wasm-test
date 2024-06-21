{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixpkgs-unstable";
    zig.url = "github:mitchellh/zig-overlay";
  };

  outputs = { nixpkgs, ... }:
  let
    system = "x86_64-linux";
    pkgs = import nixpkgs {
      inherit system;
      # overlays = [
      #   zig.overlays.default
      # ];
    };
  in {
    devShells.${system}.default = pkgs.mkShell.override {
      stdenv = pkgs.clangStdenv;
    } {
      packages = with pkgs; [
        # pkgs.zigpkgs."0.13.0"
        zig
        llvmPackages_18.bintools-unwrapped
        clang-tools_15
        wit-bindgen
        wasm-tools
        bear
        wabt
        wasmtime
      ];

      buildInputs = with pkgs; [
        pkgsCross.wasi32.wasilibc
        pkgsCross.wasi32.clangStdenv.cc
      ];

      nativeBuildInputs = with pkgs; [
        pkgsCross.wasi32.wasilibc
        llvmPackages_18.stdenv.cc
      ];

      LD_LIBRARY_PATH = "${pkgs.lib.makeLibraryPath [pkgs.pkgsCross.wasi32.wasilibc]}";

      shellHook = ''
        alias clang="clang -Wall -Wextra -Wpedantic -std=c99";
      '';
    };
  };
}
