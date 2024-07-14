from collections import defaultdict

class Solution:
    def countOfAtoms(self, formula: str) -> str:
        stack = []
        element_count = defaultdict(int)
        i = 0
        n = len(formula)

        while i < n:
            c = formula[i]
            i += 1

            if c == '(':
                # Push the current map to stack and reset for the new scope inside parenthesis
                stack.append(element_count)
                element_count = defaultdict(int)

            elif c == ')':
                # Calculate the multiplier for the elements inside the parenthesis
                multiplier = 0
                while i < n and formula[i].isdigit():
                    multiplier = multiplier * 10 + int(formula[i])
                    i += 1
                if multiplier == 0:
                    multiplier = 1
                
                # Pop from stack and update counts with the multiplier
                if stack:
                    temp_map = element_count
                    element_count = stack.pop()
                    for element, count in temp_map.items():
                        element_count[element] += count * multiplier

            else:
                # Extract the element name
                start = i - 1
                while i < n and formula[i].islower():
                    i += 1
                element = formula[start: i]

                # Extract the count of the element
                count = 0
                while i < n and formula[i].isdigit():
                    count = count * 10 + int(formula[i])
                    i += 1
                if count == 0:
                    count = 1

                # Update the count of the element
                element_count[element] += count

        # Format the result
        result = ""
        for element in sorted(element_count):
            result += element
            if element_count[element] > 1:
                result += str(element_count[element])

        return result