def merge_sort(data):
  """
  Sorts a list of numbers using the merge sort algorithm.

  Args:
    data: A list of numbers.

  Returns:
    A new list containing the sorted data.
  """

  if len(data) <= 1:
    return data

  # Divide the list in half
  middle = len(data) // 2
  left, right = data[:middle], data[middle:]

  # Recursively sort the left and right halves
  left = merge_sort(left)
  right = merge_sort(right)

  # Merge the sorted halves
  return merge(left, right)

def merge(left, right):
  """
  Merges two sorted lists into a single sorted list.

  Args:
    left: A sorted list of numbers.
    right: A sorted list of numbers.

  Returns:
    A new list containing the merged data.
  """

  merged = []
  i, j = 0, 0
  while i < len(left) and j < len(right):
    if left[i] <= right[j]:
      merged.append(left[i])
      i += 1
    else:
      merged.append(right[j])
      j += 1

  merged.extend(left[i:])
  merged.extend(right[j:])

  return merged

# Original data
data = [159, 185, -310, 250, 643, 237, -423, 860, 450, 531]

# Sort the data using merge sort
sorted_data = merge_sort(data)

# Print the sorted data
print("Sorted data:", sorted_data)

# Draw the tree of calls to mergesort algorithm

def draw_tree(data, depth=0):
  """
  Recursively draws the tree of calls to mergesort algorithm.

  Args:
    data: A list of numbers.
    depth: The current depth of the tree.
  """

  if len(data) <= 1:
    return

  # Divide the list in half
  middle = len(data) // 2
  left, right = data[:middle], data[middle:]

  # Draw the left and right subtrees
  print(" " * depth, "-", left)
  draw_tree(left, depth + 1)
  print(" " * depth, "-", right)
  draw_tree(right, depth + 1)

  # Merge the sorted halves (not actually needed for drawing the tree)
  # merge(left, right)

# Draw the tree
print("Call tree:")
draw_tree(data)
