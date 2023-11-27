use chunk::{Chunk, OpCode::*};
use debug::disassemble_chunk;

mod chunk;
mod debug;
mod memory;
mod value;


fn main() {
    let mut chunk: Chunk = Chunk::new();

    let constant = chunk.add_constant(value::Value { value: 1.2 });
    chunk.write(OpConstant as u8, 123);
    chunk.write(constant, 123);

    chunk.write(OpReturn as u8, 123);
    disassemble_chunk(&chunk, "test chunk");
    chunk.free();
}
