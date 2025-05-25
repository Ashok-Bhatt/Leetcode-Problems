/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    const x = await promise1.then((num)=>num);
    const y = await promise2.then((num)=>num);
    return new Promise(resolve => setTimeout(() => resolve(x+y), 100));
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */