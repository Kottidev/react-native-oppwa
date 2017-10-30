# react-native-oppwa
A React Native library for Oppwa, the Open Payment Platform

[![NPM](https://nodei.co/npm/react-native-oppwa.png?downloads=true&downloadRank=true&stars=true)](https://nodei.co/npm/react-native-oppwa/)


## Installation

### 1. Add Oppwa to your project

- First, set up Oppwa in your app as instructed on [Oppwa](https://docs.oppwa.com/).  This includes downloading the oppwa app and walking through the setup steps (downloading the SDK, adding it to your project and making some changes to your project).

### 2. Add react-native-oppwa

#### Automatically

`react-native install react-native-oppwa`, or with [yarn](https://github.com/rnpm/rnpm): `rnpm install react-native-oppwa`

React Native / rnpm will automatically link all the necessary libraries for both iOS and Android.

If the installation goes off without a hitch, you can now skip to the **[ Usage section](#usage)** 

#### Manually

`yarn add react-native-oppwa --save`

- Alternatively for Android, if you **don't** use Android studio you can skip the first step and instead follow the steps described in [`Android`](#android) **as well as** the steps in [`Android without Android Studio`](#no_android_studio).


##### Manually iOS support

Download the [Open Payment Platform SDK](https://docs.oppwa.com/tutorials/mobile-sdk/first-integration) and place the two
frameworks in the `ios` directory. You may
want to add this directory to your `.gitignore` as they take up a decent amount
of space and will slow down Git.

You will also need to modify the Run Script Phase that you likely added to Build
Phases so that it points to the correct location for the Oppwa framework. If
you placed the framework directly under `ios/Oppwa` as specified above,t
the contents of the script will then be:


Then do the following:

- Open your project in Xcode
- Run ```open node_modules/react-native-oppwa/ios```
- Drag `RNOppwa.xcodeproj` into your `Libraries` group
- Select your main project in the navigator to bring up settings
- Under `Build Phases` expand the `Link Binary With Libraries` header
- Scroll down and click the `+` to add a library
- Find and add `libRNOppwa.a` under the `Workspace` group
- ⌘+B

<a name="android"></a>
##### Android

*Note: Android support requires React Native 0.16 or later 

* Edit `android/settings.gradle` to look like this (without the +):

  ```diff
  rootProject.name = 'MyApp'

  include ':app'

  + include ':react-native-oppwa'
  + project(':react-native-oppwa').projectDir = new File(rootProject.projectDir, '../node_modules/react-native-oppwa/android')
  ```

* Edit `android/app/build.gradle` (note: **app** folder) to look like this: 

  ```diff
  apply plugin: 'com.android.application'

  android {
    ...
  }

  dependencies {    
    compile 'com.android.support:appcompat-v7:23.0.0'
    compile 'com.facebook.react:react-native:0.19.+'
  + compile project(':react-native-oppwa')
  }
  ```

*  Edit your `MainActivity.java` (deep in `android/app/src/main/java/...`) to look like this (note **two** places to edit):

  ```diff
  package com.myapp;

  + import com.oppwa.OppwaPackage;

  ....
  public class MainActivity extends ReactActivity {
    @Override
    protected List<ReactPackage> getPackages() {
        return Arrays.<ReactPackage>asList(
  +         new OppwaPackage(),
            new MainReactPackage()
        );
    }
  }
  ```

Make sure you also follow the steps described in [`Android`](#android).


* Edit your `AndroidManifest.xml` (in `android/app/src/main/`) to look like this. Make sure to enter your oppwa API key after `android:value=`, you can find your key on your oppwa organisation page.

  ```diff
  <manifest xmlns:android="http://schemas.android.com/apk/res/android"
      [...]
      <application
        [...]
  +       <service
  +      android:name="com.oppwa.mobile.connect.service.ConnectService"
  +    android:exported="false"/>
      </application>
  +   <uses-permission android:name="android.permission.INTERNET" />
  </manifest>
  ```

## Usage

**Note: .**



## License
MIT Mohamed Anouar KOTTI © 2017


[rnpm]: https://github.com/rnpm/rnpm
