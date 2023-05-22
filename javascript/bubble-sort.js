// Time: O(n^2)
// Space: O(1)
const bubbleSortBasic = (arr) => {
    for (let i = 0; i < arr.length; i++) {
        for (let j = 0; j < (arr.length - i - 1); j++) {
            if (arr[j] > arr[j + 1]) {
                let temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp
            }
        }
    }

    return arr;
}

// Time (best): O(n)
// Time (worst): O(n^2)
// Space: O(1)
const bubbleSortImproved = (arr) => {
  let swapped;

  do {
    swapped = false;
    for (let i = 0; i < arr.length - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        let temp = arr[i]

        arr[i] = arr[i + 1]
        arr[i + 1] = temp
        swapped = true;
      }
    }
  } while (swapped);

  return arr;
};


// let arr = [234, 43, 55, 63, 5, 6, 235, 547];
// console.log(bubbleSortImproved(arr))