// Time: O(n^2)
// Space: O(1)
const selectionSort = (arr) => {
  for (let i = 0; i < arr.length; i++) {
    let minIndex = i;
    
    for (let j = 0 + i; j < arr.length; j++) {
      if (arr[minIndex] > arr[j]) {
        minIndex = j;
      }
    }

    if (minIndex !== i) {
      const temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }

  return arr;
}

let arr = [234, 43, 55, 63, 5, 6, 235, 547];
console.log(selectionSort(arr));