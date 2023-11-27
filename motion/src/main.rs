use chunk::{Chunk, OpCode::*};
use debug::disassemble_chunk;

mod chunk;
mod debug;
mod memory;

fn main() {
    let mut chunk: Chunk = Chunk { count: 0, capacity: 0, code: vec![] };
    chunk.init_chunk();
    chunk.write_chunk(OpReturn);
    disassemble_chunk(&chunk, "test chunk");
    chunk.free_chunk();
}