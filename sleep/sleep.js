/**
 * @param {number} millis
 */
async function sleep(milliseconds) {
	await new Promise(res => setTimeout(res, milliseconds)); 
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */