use std::process::exit;

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
    new_vec.clone_from_slice(&vec[..old_count]);

    new_vec
}

pub fn reallocate<T>(vec: Vec<T>, new_size: usize) -> Vec<T> {
    if new_size == 0 {
        Vec::new()
    } else {
        let mut new_vec = Vec::with_capacity(new_size);
        new_vec.extend(vec.into_iter());
        if new_vec.is_empty() {exit(1);}
        new_vec
    }
}

pub fn free_array<T>(vec: &Vec<T>, _old_count: usize) -> &Vec<T> {
    // Dropping the vector will deallocate its memory
    vec
}