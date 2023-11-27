use crate::chunk::*;

pub fn disassemble_chunk(chunk: &Chunk, name: &str) {
    println!("== {} ==", name);
    let mut offset: usize = 0;
    for _ in 0..chunk.count {
        offset = disassemble_instruction(&chunk, offset)
    }
}

pub fn disassemble_instruction(chunk: &Chunk, offset: usize) -> usize {
    print!("{:04} ", offset);
    let instruction = chunk.code[offset];
    match instruction {
        OpCode::OpReturn => {
            return simple_instruction("OP_RETURN".to_string(), offset)
        }
    }
}

pub fn simple_instruction(name: String, offset: usize) -> usize{
    println!("{name}");
    return offset + 1;
}