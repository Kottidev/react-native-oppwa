/**
 * @providesModule Oppwa
 * @flow
 */
import { NativeModules, NativeEventEmitter } from 'react-native';
import INTERNALS from './internals';

const OppwaCoreModule = NativeModules.RNOppwa;

class FirebaseCore {
  constructor() {
    this._nativeEmitters = {};
    this._nativeSubscriptions = {};

    if (!OppwaCoreModule) {
      throw new Error(INTERNALS.STRINGS.ERROR_MISSING_CORE);
    }
  }

  /**
     * SDK transactionPayment
     *
     * @param options
     * @return {*}
     */
  transactionPayment(options: Object = {}) {
    if (!isObject(options)) {
      throw new Error(INTERNALS.STRINGS.ERROR_INIT_OBJECT);
    }

    if (!options.holderName) {
      throw new Error(INTERNALS.STRINGS.ERROR_MISSING_OPT('holderName'));
    }

    if (!options.cardNumber) {
      throw new Error(INTERNALS.STRINGS.ERROR_MISSING_OPT('cardNumber'));
    }

    if (!options.month) {
      throw new Error(INTERNALS.STRINGS.ERROR_MISSING_OPT('month'));
    }

    if (!options.year) {
      throw new Error(INTERNALS.STRINGS.ERROR_MISSING_OPT('year'));
    }

    if (!options.cvv) {
      throw new Error(INTERNALS.STRINGS.ERROR_MISSING_OPT('cvv'));
    }

    return OppwaCoreModule.transactionPayment(options);
  }

  isValidNumber(options: Object = {}) {
    if (!isObject(options)) {
      throw new Error(INTERNALS.STRINGS.ERROR_INIT_OBJECT);
    }

    if (!options.cardNumber) {
      throw new Error(INTERNALS.STRINGS.ERROR_MISSING_OPT('cardNumber'));
    }

    return OppwaCoreModule.isValidNumber(options);
  }
}

export default new FirebaseCore();
