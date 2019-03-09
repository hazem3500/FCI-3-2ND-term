// Banker Algorithm
const numOfProcesses = 6;
const numOfResourceType = 6;

const allocation = [
  [0, 1, 2],
  [1, 0, 0],
  [1, 3, 2],
  [0, 5, 2],
  [2, 1, 2],
  [1, 1, 4]
];
const max = [[4, 1, 4], [1, 4, 0], [2, 3, 6], [0, 6, 4], [3, 3, 3], [2, 6, 6]];
let available = [3, 3, 2];
let request = [2, 0, 3];
const need = max.map((processes, i) => {
  return processes.map((processAllocation, j) => {
    return processAllocation - allocation[i][j];
  });
});
const processesFinished = [false, false, false, false, false];

banker();

if (isArrSmaller(request, need[1]) && isArrSmaller(request, available)) {
  available = subtractArray(available, request);
  allocation[1] = addArray(allocation[1], request);
  need[1] = subtractArray(need[1], request);
  console.log({ available, allocation, need });
  banker();
}

function isArrSmaller(arr1, arr2) {
  return arr1.every((item, i) => {
    return item <= arr2[i];
  });
}

function addArray(arr1, arr2) {
  return arr1.map((item, i) => {
    return item + arr2[i];
  });
}

function subtractArray(arr1, arr2) {
  return arr1.map((item, i) => {
    return item - arr2[i];
  });
}

function banker() {
  console.log(need);

  for (let i = 0; i < numOfProcesses; i++) {
    const currProcessIndex = need.findIndex((need, j) => {
      return !processesFinished[j] && isArrSmaller(need, available);
    });
    if (currProcessIndex === -1) {
      console.log("UNSAFE");
      break;
    }
    processesFinished[currProcessIndex] = true;
    available = addArray(allocation[currProcessIndex], available);
    console.log(`p${currProcessIndex + 1}`, allocation[currProcessIndex], {
      available
    });
  }
}
