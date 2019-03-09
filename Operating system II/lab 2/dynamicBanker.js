// Banker Algorithm
const numOfProcesses = 6;

let stack = [];

const allocation = [[0, 1, 0], [2, 0, 0], [3, 0, 2], [2, 1, 1], [0, 0, 2]];
const max = [[7, 5, 3], [3, 2, 2], [9, 0, 2], [2, 2, 2], [4, 3, 3]];
let available = [3, 3, 2];
// let request = [2, 0, 3];
const need = max.map((processes, i) => {
  return processes.map((processAllocation, j) => {
    return processAllocation - allocation[i][j];
  });
});
let processesFinished = [false, false, false, false, false];

banker();

// if (isArrSmaller(request, need[1]) && isArrSmaller(request, available)) {
//   available = subtractArray(available, request);
//   allocation[1] = addArray(allocation[1], request);
//   need[1] = subtractArray(need[1], request);
//   console.log({ available, allocation, need });
//   banker();
// }

function banker() {
  for (let i = 0; i < numOfProcesses; i++) {
    need.forEach((currNeed, j) => {
      const isProcessValid = checkProcess(currNeed, j);
      if (!isProcessValid) addToStack(currNeed);
    });
  }

  let isSafe = true;

  for (let i = stack.length - 1; i > -1; i--) {
    const isProcessValid = checkProcess(stack[i], i);
    if (!isProcessValid) {
      console.log(available, stack[i]);

      isSafe = false;
      break;
    }
  }
  console.log(isSafe ? "Safe" : "UNSAFE");
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

function checkProcess(need, index) {
  if (isArrSmaller(need, available)) {
    processesFinished[index] = true;
    available = addArray(allocation[index], available);
    return true;
  }
  return false;
}

function addToStack(need) {
  const needIndex = stack.findIndex(stackNeed => stackNeed === need);
  if (needIndex === -1) {
    stack.push(need);
    stack = stack.sort((firstNeed, secondNeed) =>
      isArrSmaller(firstNeed, secondNeed)
    );
  }
}
