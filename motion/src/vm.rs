use crate::{chunk::OpCode::*, chunk::*, value::ValueArray};

pub struct Vm {
    chunk: Chunk,
    ip: usize,
}

pub const VM: Vm = Vm::new();

pub enum InterpretResult {
    InterpretOk,
    InterpretCompileErr,
    InterpretRuntimeErr,
}

impl Vm {
    pub const fn new() -> Self {
        Self {
            chunk: Chunk {
                count: 0,
                capacity: 0,
                code: vec![],
                lines: vec![],
                constants: ValueArray::new(),
            },
            ip: 0,
        }
    }

    pub fn init() -> Vm {
        Vm::new()
    }

    pub fn free(self: Self) {}

    fn read_byte(&mut self) -> Option<u8> {
        if self.ip < self.chunk.code.len() {
            let byte = self.chunk.code[self.ip];
            self.ip += 1;
            Some(byte)
        } else {
            None
        }
    }

    pub fn interpret(mut vm: Vm, chunk: Chunk) -> InterpretResult {
        vm.chunk = chunk;
        vm.ip = vm.chunk.code[vm.ip] as usize;
        return Self::run(vm);
    }

    pub fn run(mut vm: Vm) -> InterpretResult {
        loop {
            if let Some(instruction) = Vm::read_byte(vm) {
                match instruction {
                    OP_RETURN => {
                        return InterpretResult::INTERPRET_OK;
                    }
                    // Handle other opcodes as needed
                    _ => {
                        // Handle unknown opcode or implement other cases
                        unimplemented!("Opcode not implemented: {}", instruction);
                    }
                }
            } else {
                break; // End of bytecode
            }
        }
    }
}
