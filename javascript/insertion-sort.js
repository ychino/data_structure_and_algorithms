// // Time (best): O(n)
// // Time (worst): O(n^2)
// // Space: O(n)
const insertionSort = (arr) => {
  for (let i = 1; i < arr.length; i++) {
    let currentValue = arr[i];

    let j;
    for (j = i - 1; j >= 0 && arr[j] > currentValue; j--) {
      arr[j + 1] = arr[j];
    }

    arr[j + 1] = currentValue;
  }

  return arr;
}

const arr = [234, 43, 55, 63, 5, 6, 235, 547];
console.log(insertionSort(arr))