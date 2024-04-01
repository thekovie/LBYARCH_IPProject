# SAXPY Implementation for C & x86-64
In this project, we will showcase the implementation of SAXPY and the test cases we conducted in the program.

_This project is for the LBYARCH class at De La Salle University._

![image](https://github.com/thekovie/LBYARCH_IPProject/assets/40118781/4940c72e-2933-48e8-8b1e-9e63cfbe67f3)

# Introduction
For context, the formula of SAXPY is:

$Z = A * X + Y$

Let us define the variables:
- Where $A$ is a single-precision floating-point variable.
- Where $X$, $Y$, and $Z$ are single-precision floating-point variables.

# User Input
The user inputs the size of the vector based on the options given below:

![Screenshot 2024-04-01 162207](https://github.com/thekovie/LBYARCH_IPProject/assets/40118781/26ff25e3-9487-4135-9fbe-b9006174f512)


# Output
The program outputs $X$, $Y$, and $Z$ for C and Assembly language. It also shows the average time to perform the calculation for both languages.

![image](https://github.com/thekovie/LBYARCH_IPProject/assets/40118781/d39b03d9-8d53-4b12-ae20-5c72c480712d)


# Test Cases
We will now show you the test cases we conducted. We conducted the tests for $2^{20}$, $2^{24}$, and $2^{29}$, but we cannot make one for $2^{30}$ because the test cannot be conducted with our local machines.


## Test Cases for $2^{20}$ 

**Debug Mode**

![Screenshot 2024-04-01 151943](https://github.com/thekovie/LBYARCH_IPProject/assets/40118781/5d17b7ae-0925-45c8-abde-aae006f50df5)

**Release Mode**

![Screenshot 2024-04-01 152059](https://github.com/thekovie/LBYARCH_IPProject/assets/40118781/95a9c21b-e9b0-4a80-822e-db39c6783788)

## Test Cases for $2^{24}$

**Debug Mode**

![Screenshot 2024-04-01 152117](https://github.com/thekovie/LBYARCH_IPProject/assets/40118781/c2cfa2ae-66bd-475d-b1ed-deeb2bda2191)

**Release Mode**

![Screenshot 2024-04-01 152139](https://github.com/thekovie/LBYARCH_IPProject/assets/40118781/e5bde938-6a1e-45fe-8748-b97c901eba8d)

## Test Cases for $2^{29}$

**Debug Mode**

![Screenshot 2024-04-01 151700](https://github.com/thekovie/LBYARCH_IPProject/assets/40118781/03508565-3f27-4805-8d88-1fef9447b2fe)

**Release Mode**

![Screenshot 2024-04-01 151830](https://github.com/thekovie/LBYARCH_IPProject/assets/40118781/ce81cfe1-d742-4503-9c0b-fc669f06f657)

## Test Case for Custom Input ($1234567$)

**Debug Mode**

![Screenshot 2024-04-01 152257](https://github.com/thekovie/LBYARCH_IPProject/assets/40118781/dfb27ffe-481c-47c3-9f07-664587d053da)

**Release Mode**

![Screenshot 2024-04-01 152323](https://github.com/thekovie/LBYARCH_IPProject/assets/40118781/380d4df3-61bd-40bd-a4af-944fc2112d7a)

# Analysis








