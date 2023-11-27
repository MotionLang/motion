use crate::{memory::*, value::*,};

#[derive(Clone, Copy, Debug)]
pub enum OpCode {
    OpReturn,
    OpConstant,

}

impl Default for OpCode {
    fn default() -> Self {
        OpCode::OpReturn
    }
}

impl From<u8> for OpCode {
    fn from(value: u8) -> Self {
        match value {
            0 => OpCode::OpReturn,
            1 => OpCode::OpConstant,
            // Add other mappings for different values
            _ => panic!("Invalid OpCode: {}", value),
        }
    }
}


pub struct Chunk {
    pub count: usize,
    pub capacity: usize,
    pub code: Vec<u8>,
    pub lines: Vec<usize>,
    pub constants: ValueArray,
}

impl Chunk {
    pub fn new() -> Self {
        Self {
            count: 0,
            capacity: 0,
            code: vec![],
            lines: vec![],
            constants: ValueArray::new(),
        }
    }

    pub fn write(&mut self, byte: u8, line: usize) {
        if self.capacity < (self.count + 1) {
            let old_capacity: usize = self.capacity;
            self.capacity = grow_capacity(old_capacity);
            self.code = grow_array::<u8>(&self.code, old_capacity as usize, self.capacity);
            self.lines = grow_array(&self.lines, old_capacity, self.capacity);
        }

        self.code[self.count] = byte;
        self.lines[self.count] = line;
        self.count += 1;
    }

    pub fn add_constant(&mut self, value: Value) -> u8 {
        ValueArray::write(&mut self.constants, value);
        return (self.constants.count - 1) as u8;
    }

    pub fn free(&mut self) {
        free_array(&self.code, self.capacity);
        free_array(&self.lines, self.capacity);
        ValueArray::free(&mut self.constants);
        *self = Chunk::new();
    }
}
