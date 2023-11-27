use std::vec::*;

pub fn grow_capacity(capacity: usize) -> usize {
    if capacity < 8 {
        8
    } else {
        capacity * 2
    }
}

pub fn grow_array<T: Clone + std::default::Default>(vec: &Vec<T>, old_count: usize, new_count: usize) -> Vec<T> {
    let mut new_vec = Vec::with_capacity(new_count);
    
    // Ensure that the length of the new vector is set appropriately
    new_vec.resize(new_count, std::default::Default::default());

    // Clone the elements from the old vector to the new one
    new_vec[..old_count].clone_from_slice(&vec[..old_count]);

    // Manually initialize the additional elements (if any)
    for i in old_count..new_count {
        new_vec[i] = std::default::Default::default();
    }

    new_vec
}

pub fn free_array<T>(vec: &Vec<T>, _old_count: usize) -> &Vec<T> {
    // Dropping the vector will deallocate its memory
    vec
}
