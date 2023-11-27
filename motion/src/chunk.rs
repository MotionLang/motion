use crate::memory::*;

pub enum OpCode {
    OpReturn,
}

pub  struct Chunk {
    count:  usize,
    capacity: usize,
    code: Vec<u8>,
}

impl Chunk {
    pub fn init_chunk(&mut self) {
        self.count = 0;
        self.capacity = 0;
        self.code = vec![];
    }

    pub fn write_chunk(&mut self, byte: u8) {
        if self.capacity < (self.count + 1) {
            let old_capacity: usize = self.capacity;
            self.capacity = grow_capacity(old_capacity);
            self.code = grow_array::<u8>(&self.code, old_capacity as usize, self.capacity);
        }

        self.code[self.count as usize] = byte;
        self.count += 1;
    }

    pub fn free_chunk(&mut self) {
        free_array(&self.code, self.capacity);
        self.init_chunk();
    }
}