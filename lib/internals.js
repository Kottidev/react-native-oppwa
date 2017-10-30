import { Platform, NativeModules } from 'react-native';

const GRADLE_DEPS = {
  admob: 'ads'
};

const PLAY_SERVICES_CODES = {
  1: {
    code: 'SERVICE_MISSING',
    message: 'Google Play services is missing on this device.'
  },
  2: {
    code: 'SERVICE_VERSION_UPDATE_REQUIRED',
    message:
      'The installed version of Google Play services on this device is out of date.'
  },
  3: {
    code: 'SERVICE_DISABLED',
    message:
      'The installed version of Google Play services has been disabled on this device.'
  },
  9: {
    code: 'SERVICE_INVALID',
    message:
      'The version of the Google Play services installed on this device is not authentic.'
  },
  18: {
    code: 'SERVICE_UPDATING',
    message: 'Google Play services is currently being updated on this device.'
  },
  19: {
    code: 'SERVICE_MISSING_PERMISSION',
    message:
      "Google Play service doesn't have one or more required permissions."
  }
};

export default {
  // default options
  OPTIONS: {
    logLevel: 'warn',
    errorOnMissingPlayServices: true,
    promptOnMissingPlayServices: true
  },

  FLAGS: {
    checkedPlayServices: false
  },

  ERROR_INIT_OBJECT:
    'Firebase.initializeApp(options <-- requires a valid configuration object.',
  ERROR_INIT_STRING_NAME:
    'Firebase.initializeApp(options, name <-- requires a valid string value.',

  /**
     * @return {string}
     */
  ERROR_MISSING_CB(method) {
    return `Missing required callback for method ${method}().`;
  },

  /**
     * @return {string}
     */
  ERROR_MISSING_ARG(type, method) {
    return `Missing required argument of type '${type}' for method '${method}()'.`;
  },

  /**
     * @return {string}
     */
  ERROR_MISSING_ARG_NAMED(name, type, method) {
    return `Missing required argument '${name}' of type '${type}' for method '${method}()'.`;
  },

  /**
     * @return {string}
     */
  ERROR_ARG_INVALID_VALUE(name, expected, got) {
    return `Invalid value for argument '${name}' expected value '${expected}' but got '${got}'.`;
  },

  /**
     * @return {string}
     */
  ERROR_PROTECTED_PROP(name) {
    return `Property '${name}' is protected and can not be overridden by extendApp.`;
  },

  /**
     * @return {string}
     */
  ERROR_APP_NOT_INIT(appName) {
    return `The [${appName}] oppwa app has not been initialized!`;
  },

  /**
     * @param optName
     * @return {string}
     * @constructor
     */
  ERROR_MISSING_OPT(optName) {
    return `Failed to initialize app. PaymentOptions missing or invalid '${optName}' property.`;
  },

  /**
     * @return {string}
     */
  ERROR_NOT_APP(namespace) {
    return `Invalid OppwaApp instance passed to oppwa.${namespace}(app <--).`;
  },

  /**
     * @return {string}
     */
  ERROR_UNSUPPORTED_CLASS_METHOD(className, method) {
    return `${className}.${method}() is unsupported by the native Firebase SDKs.`;
  },

  /**
     * @return {string}
     */
  ERROR_UNSUPPORTED_CLASS_PROPERTY(className, property) {
    return `${className}.${property} is unsupported by the native Firebase SDKs.`;
  },

  /**
     * @return {string}
     */
  ERROR_UNSUPPORTED_MODULE_METHOD(module, method) {
    return `oppwa.${module._NAMESPACE}().${method}() is unsupported by the native Firebase SDKs.`;
  }
};
