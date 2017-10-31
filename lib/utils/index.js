// @flow
import { Platform } from 'react-native';

// todo cleanup unused utilities from legacy code

// modeled after base64 web-safe chars, but ordered by ASCII
const PUSH_CHARS = '-0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz';
const AUTO_ID_CHARS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
const hasOwnProperty = Object.hasOwnProperty;

// const DEFAULT_CHUNK_SIZE = 50;

const REGEXP_FIELD_NAME = new RegExp(
  `^(?:\\.?((?:(?:[A-Za-z_][A-Za-z_0-9]*)|(?:[A-Za-z_][A-Za-z_0-9]*))+))$`
);
const REGEXP_FIELD_PATH = new RegExp(
  `^((?:(?:[A-Za-z_][A-Za-z_0-9]*)|(?:[A-Za-z_][A-Za-z_0-9]*))+)(?:\\.((?:(?:[A-Za-z_][A-Za-z_0-9]*)|(?:[A-Za-z_][A-Za-z_0-9]*))+))*$`
);

/**
 * Deep get a value from an object.
 * @param object
 * @param path
 * @param joiner
 * @returns {*}
 */
export function deepGet(object: Object,
                        path: string,
                        joiner?: string = '/'): any {
  const keys = path.split(joiner);

  let i = 0;
  let tmp = object;
  const len = keys.length;

  while (i < len) {
    const key = keys[i++];
    if (!tmp || !hasOwnProperty.call(tmp, key)) return null;
    tmp = tmp[key];
  }

  return tmp;
}

/**
 * Deep check if a key exists.
 * @website https://github.com/Salakar/deeps
 * @param object
 * @param path
 * @param joiner
 * @returns {*}
 */
export function deepExists(object: Object,
                           path: string,
                           joiner?: string = '/'): boolean {
  const keys = path.split(joiner);

  let i = 0;
  let tmp = object;
  const len = keys.length;

  while (i < len) {
    const key = keys[i++];
    if (!tmp || !hasOwnProperty.call(tmp, key)) return false;
    tmp = tmp[key];
  }

  return tmp !== undefined;
}

/**
 * Deep Check if obj1 keys are contained in obj2
 * @param obj1
 * @param obj2
 * @returns {boolean}
 */
export function areObjectKeysContainedInOther(obj1 : Object, obj2: Object): boolean {
  if (!isObject(obj1) || !isObject(obj2)) {
    return false;
  }
  const keys1 = Object.keys(obj1);
  const keys2 = Object.keys(obj2);
  if (isArrayContainedInOther(keys1, keys2)) {
    return keys1.filter((key) => {
      return isObject(obj1[key]);
    }).reduce((acc, cur) => {
      return acc && areObjectKeysContainedInOther(obj1[cur], obj2[cur]);
    }, true);
  }
  return false;
}

/**
 * Check if arr1 is contained in arr2
 * @param arr1
 * @param arr2
 * @returns {boolean}
 */
export function isArrayContainedInOther(arr1: Array, arr2: Array): boolean {
  if (!Array.isArray(arr1) || !Array.isArray(arr2)) {
    return false;
  }
  return arr1.reduce((acc, cur) => {
    return acc && arr2.includes(cur);
  }, true);
}

/**
 * Simple is object check.
 * @param item
 * @returns {boolean}
 */
export function isObject(item: any): boolean {
  return (item && typeof item === 'object' && !Array.isArray(item) && item !== null);
}

/**
 * Simple is function check
 * @param item
 * @returns {*|boolean}
 */
export function isFunction(item?: any): boolean {
  return Boolean(item && typeof item === 'function');
}

/**
 * Simple is string check
 * @param value
 * @return {boolean}
 */
export function isString(value: any): boolean {
  return typeof value === 'string';
}

/**
 * Firestore field name/path validator.
 * @param field
 * @param paths
 * @return {boolean}
 */
export function isValidFirestoreField(field, paths) {
  return (paths ? REGEXP_FIELD_PATH : REGEXP_FIELD_NAME).test(field);
}

// platform checks
export const isIOS = Platform.OS === 'ios';
export const isAndroid = Platform.OS === 'android';


/**
 *
 * @param string
 * @returns {*}
 */
export function tryJSONParse(string: string | null): any {
  try {
    return string && JSON.parse(string);
  } catch (jsonError) {
    return string;
  }
}

/**
 *
 * @param data
 * @returns {*}
 */
export function tryJSONStringify(data: any): string | null {
  try {
    return JSON.stringify(data);
  } catch (jsonError) {
    return null;
  }
}


// noinspection Eslint
export const windowOrGlobal = (typeof self === 'object' && self.self === self && self) || (typeof global === 'object' && global.global === global && global) || this;

/**
 * No operation func
 */
export function noop(): void {
}


// /**
//  * Delays chunks based on sizes per event loop.
//  * @param collection
//  * @param chunkSize
//  * @param operation
//  * @param callback
//  * @private
//  */
// function _delayChunk(collection: Array<*>,
//                      chunkSize: number,
//                      operation: Function,
//                      callback: Function): void {
//   const length = collection.length;
//   const iterations = Math.ceil(length / chunkSize);
//
//   // noinspection ES6ConvertVarToLetConst
//   let thisIteration = 0;
//
//   setImmediate(function next() {
//     const start = thisIteration * chunkSize;
//     const _end = start + chunkSize;
//     const end = _end >= length ? length : _end;
//     const result = operation(collection.slice(start, end), start, end);
//
//     if (thisIteration++ > iterations) {
//       callback(null, result);
//     } else {
//       setImmediate(next);
//     }
//   });
// }
//
// /**
//  * Async each with optional chunk size limit
//  * @param array
//  * @param chunkSize
//  * @param iterator
//  * @param cb
//  */
// export function each(array: Array<*>,
//                      chunkSize: number | Function,
//                      iterator: Function,
//                      cb?: Function): void {
//   if (typeof chunkSize === 'function') {
//     cb = iterator;
//     iterator = chunkSize;
//     chunkSize = DEFAULT_CHUNK_SIZE;
//   }
//
//   if (cb) {
//     _delayChunk(array, chunkSize, (slice, start) => {
//       for (let ii = 0, jj = slice.length; ii < jj; ii += 1) {
//         iterator(slice[ii], start + ii);
//       }
//     }, cb);
//   }
// }

/**
 * Returns a string typeof that's valid for Firebase usage
 * @param value
 * @return {*}
 */
export function typeOf(value: any): string {
  if (value === null) return 'null';
  if (Array.isArray(value)) return 'array';
  return typeof value;
}

// /**
//  * Async map with optional chunk size limit
//  * @param array
//  * @param chunkSize
//  * @param iterator
//  * @param cb
//  * @returns {*}
//  */
// export function map(array: Array<*>,
//                     chunkSize: number | Function,
//                     iterator: Function,
//                     cb?: Function): void {
//   if (typeof chunkSize === 'function') {
//     cb = iterator;
//     iterator = chunkSize;
//     chunkSize = DEFAULT_CHUNK_SIZE;
//   }
//
//   const result = [];
//   _delayChunk(array, chunkSize, (slice, start) => {
//     for (let ii = 0, jj = slice.length; ii < jj; ii += 1) {
//       result.push(iterator(slice[ii], start + ii, array));
//     }
//     return result;
//   }, () => cb && cb(result));
// }

// /**
//  *
//  * @param string
//  * @return {string}
//  */
// export function capitalizeFirstLetter(string: String) {
//   return `${string.charAt(0).toUpperCase()}${string.slice(1)}`;
// }

// timestamp of last push, used to prevent local collisions if you push twice in one ms.
let lastPushTime = 0;

// we generate 72-bits of randomness which get turned into 12 characters and appended to the
// timestamp to prevent collisions with other clients.  We store the last characters we
// generated because in the event of a collision, we'll use those same characters except
// "incremented" by one.
const lastRandChars = [];

/**
 * Converts a code and message from a native event to a JS Error
 * @param code
 * @param message
 * @param additionalProps
 * @returns {Error}
 */
export function nativeToJSError(code: string, message: string, additionalProps?: Object = {}) {
  const error: Object = new Error(message);
  error.code = code;
  Object.assign(error, additionalProps);
  // exclude this function from the stack
  const _stackArray = error.stack.split('\n');
  error.stack = _stackArray.splice(1, _stackArray.length).join('\n');
  return error;
}

/**
 * Prepends appName arg to all native method calls
 * @param appName
 * @param NativeModule
 */
export function nativeWithApp(appName: string, NativeModule: Object) {
  const native = {};
  const methods = Object.keys(NativeModule);

  for (let i = 0, len = methods.length; i < len; i++) {
    const method = methods[i];
    native[method] = (...args) => {
      return NativeModule[method](...[appName, ...args]);
    };
  }

  return native;
}

/**
 *
 * @param object
 * @return {string}
 */
export function objectToUniqueId(object: Object): string {
  if (!isObject(object) || object === null) return JSON.stringify(object);

  const keys = Object.keys(object).sort();

  let key = '{';
  for (let i = 0; i < keys.length; i++) {
    if (i !== 0) key += ',';
    key += JSON.stringify(keys[i]);
    key += ':';
    key += objectToUniqueId(object[keys[i]]);
  }

  key += '}';
  return key;
}
