use crate::{chunk::*, value::Value};

pub fn disassemble_chunk(chunk: &Chunk, name: &str) {
    println!("== {} ==", name);
    let mut offset: usize = 0;
    for _ in 0..chunk.count {
        offset = disassemble_instruction(&chunk, offset)
    }
}

pub fn disassemble_instruction(chunk: &Chunk, offset: usize) -> usize {
    print!("{:04} ", offset);

    if offset > 0 && chunk.lines[offset] == chunk.lines[offset - 1] {
        print!("| ");
    } else {
        print!("{} ", chunk.lines[offset]);
    }

    let instruction: OpCode = chunk.code[offset].try_into().unwrap();
    match instruction {
        OpCode::OpReturn => {
            return simple_instruction("OP_RETURN".to_string(), offset)
        }
        OpCode::OpConstant => {
            return constant_instruction("OP_CONSTANT".to_string(), chunk, offset)
        }
    }
}

pub fn simple_instruction(name: String, offset: usize) -> usize{
    println!("  {name}");
    return offset + 1;
}

pub fn constant_instruction(name: String, chunk: &Chunk, offset: usize) -> usize {
    let constant = chunk.code[offset + 1];
    print!("{} \t{:?} ", name, constant);
    Value::print(chunk.constants.values[constant as usize]);
    println!();
    return offset + 2;
}
