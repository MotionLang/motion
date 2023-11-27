use crate::memory::*;

#[derive(Clone, Copy)]
pub enum OpCode {
    OpReturn,
}

impl Default for OpCode {
    fn default() -> Self {
        OpCode::OpReturn
    }
}

pub  struct Chunk {
    pub count:  usize,
    pub capacity: usize,
    pub code: Vec<OpCode>,
}

impl Chunk {
    pub fn init_chunk(&mut self) {
        self.count = 0;
        self.capacity = 0;
        self.code = vec![];
    }

    pub fn write_chunk(&mut self, byte: OpCode) {
        if self.capacity < (self.count + 1) {
            let old_capacity: usize = self.capacity;
            self.capacity = grow_capacity(old_capacity);
            self.code = grow_array::<OpCode>(&self.code, old_capacity as usize, self.capacity);
        }

        self.code[self.count as usize] = byte;
        self.count += 1;
    }

    pub fn free_chunk(&mut self) {
        free_array(&self.code, self.capacity);
        self.init_chunk();
    }
}