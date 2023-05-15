// In JavaScript, a promise is an object used to handle asynchronous operations. It represents the eventual completion or failure of an asynchronous operation and allows you to write more readable and maintainable asynchronous code.

/**
 * @param {number} millis
 */
async function sleep(millis) {
    return new Promise((resolve, reject) => {
        setTimeout(()=>{
            resolve(millis);
        }, millis);
    });
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */