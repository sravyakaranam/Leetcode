class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:

        hash_map={}
        result=[]
        for num in nums:
            if num not in hash_map:
                hash_map[num]=1
            else:
               hash_map[num]+=1 
        sorted_keys = sorted(hash_map.items(), reverse=True)
        print(sorted_keys)      
        sorted_items = sorted(sorted_keys, key=lambda item: item[1])
        print(sorted_items)
        for pair in sorted_items:
            name, value = pair  
            while value > 0:
                result.append(name)
                value -= 1

        return result